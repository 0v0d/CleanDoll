#include "Field.h"
#include "Doll.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

Doll _doll;

void Field::Initialize()
{
	_doll.SetField(this);

	_blockManager.Initialize();
	_doll.Initialize();
	_energyVessels.Initialize();
	_remainingDumpUI.Initialize();
	_adjoinBlockValue = _blockManager.GetAdjoinBlockValue();

	_remainDistance = _maxDistance;
	_blockManager.SetDoll(&_doll);
	_doll.SetDumpValue(_dustDumpValue, _waterDumpValue);

	_energyVessels.SetMaxEnergyValue(_maxDistance);
	_energyVessels.SetCurrentEnergyValue(&_remainDistance);
	_energyVessels.CheckChangeEnergyColor();
	_stageClear.Initialize();
	_gameOver.Initialize();
	_dollInitialPositionX = _dollInitialPositionY = 1;
}

void Field::ReLoad()
{
	_blockManager.ReLoad();
	_doll.ReLoad();
	_remainingDumpUI.ReLoad();
	_doll.CalcuScale(_blockManager.GetBlock(0, 0)->GetBlockSize().y, _blockManager.GetScale());
	_dustDumpValue = _initalDustValue;
	_waterDumpValue = _initalWaterValue;
	_remainingDumpUI.SetDumpValue(_dustDumpValue, _waterDumpValue);
	if (_dollInitialPositionX >= 0 && _dollInitialPositionY >= 0)SetDollPosition(_dollInitialPositionX, _dollInitialPositionY);
	_doll.SetDumpValue(_dustDumpValue, _waterDumpValue);
	_pickedBlock = _lastDistanceBlock = _blockManager.GetBlock(_dollInitialPositionX, _dollInitialPositionY);
	_energyVessels.ReLoad();
	_pickedBlock->SetPassedFlg(true);

	_stageClear.Reload();
	_gameOver.Reload();
	_routeBlockArray.clear();
	_recoveryDifferentialArray.clear();

	_remainDistance = _maxDistance;
}

void Field::SetDollPosition(int x, int y)
{
	_doll.SetPosition(_blockManager.GetBlock(x, y)->GetCenterPosition());

	_dollInitialPositionX = x;
	_dollInitialPositionY = y;

	_blockManager.SetDollOnPositon(x, y);
}

void Field::Update()
{
	_blockManager.Update();
	_doll.Update();

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_RBUTTON))
	{
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}
	_stageClear.Update();
	_gameOver.Update();

}

//ブロックを押したとき
void Field::PassedMouse(Vector2 mousePosition)
{
	if (*_onMoveDoll) return;

	Block* mouseOnBlock = _blockManager.GetMouseOnBlock(mousePosition);
	if (mouseOnBlock == nullptr) return;

	for (int i = 0; i < _adjoinBlockValue; i++)
	{
		if (mouseOnBlock != _pickedBlock->GetAdjoinBlockArray()[i])
		{
			continue;
		}
		//押されていないブロックを押したとき、押したブロックを記録
		if (!mouseOnBlock->IsPassed())
		{
			AdvanceRoute(mouseOnBlock);
		}
		//1回以上入力していて、既に押されているブロックを押したとき、巻き戻し
		else if (_distanceCount > 0)
		{
			BackRoute(mouseOnBlock);
		}
		return;
	}
}

//押したブロックを記録
void Field::AdvanceRoute(Block* mouseOnBlock)
{
	if (_remainDistance <= 0 || mouseOnBlock->GetBlockOnObject()->GetFurniture() != nullptr) return;

	_pickedBlock = mouseOnBlock;
	_pickedBlock->SetPassedFlg(true);
	_routeBlockArray.push_back(_pickedBlock);
	_distanceCount++;
	_remainDistance--;
	_energyVessels.CheckChangeEnergyColor();

	if (_pickedBlock->GetBlockOnObject()->GetAccessories() != nullptr)
	{
		if (_pickedBlock->GetBlockOnObject()->GetAccessories()->GetType() == ACCESSORIES_TYPE::ITEM)
		{
			_recoveryDifferentialArray.push_back(_maxDistance - _remainDistance);
			_remainDistance += _maxDistance - _remainDistance;
			_pickedBlock->GetBlockOnObject()->HiddenAccessoriesFlg(true);
			_energyVessels.CheckChangeEnergyColor();
		}
	}
}

//巻き戻し
void Field::BackRoute(Block* mouseOnBlock)
{

	//2つ以上のブロックを押している時に、1つ前に押したブロックを押すか、
	//1つしか押していない時に、前回の最後に押したブロックを押せば巻き戻す
	if (_distanceCount == 1 && mouseOnBlock != _lastDistanceBlock) return;
	else if (_distanceCount >= 2 && _routeBlockArray[_distanceCount - 2] != mouseOnBlock) return;
	//[_distanceCount - 2]は1つ前に押したブロックの要素を表す

	//巻き戻し処理
	if (_pickedBlock->GetBlockOnObject()->GetAccessories() != nullptr)
	{
		if (_pickedBlock->GetBlockOnObject()->GetAccessories()->GetType() == ACCESSORIES_TYPE::ITEM)
		{
			_remainDistance -= _recoveryDifferentialArray.back();
			_recoveryDifferentialArray.pop_back();
			_pickedBlock->GetBlockOnObject()->HiddenAccessoriesFlg(false);
		}
	}

	_pickedBlock->SetPassedFlg(false);
	_pickedBlock = mouseOnBlock;
	_routeBlockArray.pop_back();
	_distanceCount--;
	_remainDistance++;
	_energyVessels.CheckChangeEnergyColor();
}

//入力終了
void Field::EndOfPassed()
{
	if (_distanceCount <= 0) return;

	_doll.SetRouteBlockArray(_routeBlockArray);
	_lastDistanceBlock = _routeBlockArray.back();
	_routeBlockArray.clear();
	_distanceCount = 0;
	//_remainDistance = _maxDistance;
	_recoveryDifferentialArray.clear();


}

void Field::EndMoveDoll()
{
	if (_dustDumpValue <= 0 && _waterDumpValue <= 0)
	{
		//ゲームクリア
		_stageClear.SetGoal(true);
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StageClear();
		if (_stageClear.IsRemove())
		{
			_blockManager.Delete();
			Delete();
		}
	}
	//ゲームオーバー
	if (_remainDistance <= 0)
	{
		GameOver();
	}
}

void Field::CleanDust()
{
	_dustDumpValue--;
	_remainingDumpUI.CleanDust();
}

void Field::CleanWater()
{
	_waterDumpValue--;
	_remainingDumpUI.CleanWater();
}

void Field::ReSetStage()
{
	ReLoad();
}

void Field::GameOver()
{
	_gameOver.SetGameOver(true);
}

void Field::Render()
{
	_blockManager.Render();
	_remainingDumpUI.Render();
	_energyVessels.Render();
	_stageClear.Render();
	_gameOver.Render();
	CGraphicsUtilities::RenderString(30, 60, "%d/%d", _remainDistance, _maxDistance);
}

void Field::Delete()
{
	_routeBlockArray.clear();
	_recoveryDifferentialArray.clear();

}

void Field::Release()
{
	_blockManager.Release();
	_doll.Release();
	_energyVessels.Release();
	_remainingDumpUI.Release();
	_stageClear.Release();
	_gameOver.Release();
	Delete();
}
