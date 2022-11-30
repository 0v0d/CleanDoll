#include "Field.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void Field::Initialize()
{
	_operateDoll.SetBlockManager(&_blockManager);
	_operateDoll.SetDoll(&_doll);
	_doll.SetField(this);
	_blockManager.SetDoll(&_doll);

	_adjoinBlockValue = _blockManager.GetAdjoinBlockValue();
	_remainDistance = _maxDistance;
	_fieldUI.SetMaxEnergyValue(_maxDistance);

	_blockManager.Initialize();
	_operateDoll.Initialize();
	_doll.Initialize();
	_fieldUI.Initialize();
	_endGameProcess.Initialize();

	_doll.SetDumpValue(_dustDumpValue, _waterDumpValue);

	//�K�v�Ȃ�?
	_dollInitialPositionX = _dollInitialPositionY = 1;
}

void Field::ReLoad()
{
	_blockManager.ReLoad();
	_doll.ReLoad();
	_fieldUI.ReLoad();

	_doll.CalcuScale(_blockManager.GetBlock(0, 0)->GetBlockSize().y, _blockManager.GetScale());
	_dustDumpValue = _initalDustValue;
	_waterDumpValue = _initalWaterValue;

	if (_dollInitialPositionX >= 0 && _dollInitialPositionY >= 0)SetDollPosition(_dollInitialPositionX, _dollInitialPositionY);
	_doll.SetDumpValue(_dustDumpValue, _waterDumpValue);
	_pickedBlock = _lastDistanceBlock = _blockManager.GetBlock(_dollInitialPositionX, _dollInitialPositionY);

	_pickedBlock->SetPassedFlg(true);

	_endGameProcess.ReLoad();
	_routeBlockArray.clear();
	_recoveryDifferentialArray.clear();

	_remainDistance = _maxDistance;

	_fieldUI.SetCurrentEnergyValue(_remainDistance);

	_push = false;
}

void Field::SetDollPosition(int x, int y)
{
	_doll.SetPosition(_blockManager.GetBlock(x, y)->GetCenterPosition());

	_dollInitialPositionX = x;
	_dollInitialPositionY = y;

	SetDollOnBlockNumber(_blockManager.GetBlock(x,y));
}

void Field::SetDustDumpValue(int dumpValue) {
	_initalDustValue = _dustDumpValue = dumpValue;
	_fieldUI.SetDustDumpValue(_initalDustValue);
}

void Field::SetWaterDumpValue(int dumpValue) {
	_initalWaterValue = _waterDumpValue = dumpValue;
	_fieldUI.SetWaterDumpValue(_initalWaterValue);
}

void Field::Update()
{
	if (_push) {
		PassedMouse(_mousePos);
	}

	_blockManager.Update();
	_doll.Update();
	_endGameProcess.Update();
}

void Field::SetMousePos(Vector2 mousePos){
	_mousePos = mousePos;
	_endGameProcess.SetMousePos(mousePos);
}

void Field::Push() {
	_push = true;
	_endGameProcess.Push();
}

void Field::Pull() {
	_push = false;
	EndOfPassed();
	_endGameProcess.Pull();
}

//�u���b�N���������Ƃ�
void Field::PassedMouse(Vector2 mousePosition)
{
	if (*_onMoveDoll) return;

	Block* mouseOnBlock = _blockManager.GetMouseOnBlock(mousePosition);
	if (mouseOnBlock == nullptr) return;

	for (int i = 0; i < _adjoinBlockValue; i++)
	{
		if (mouseOnBlock != _pickedBlock->GetAdjoinBlockArray()[i])continue;
		//������Ă��Ȃ��u���b�N���������Ƃ��A�������u���b�N���L�^
		if (!mouseOnBlock->IsPassed())
		{
			AdvanceRoute(mouseOnBlock);
		}
		//1��ȏ���͂��Ă��āA���ɉ�����Ă���u���b�N���������Ƃ��A�����߂�
		else if (_routeBlockArray.size() > 0)
		{
			BackRoute(mouseOnBlock);
		}
		return;
	}
}

//�������u���b�N���L�^
void Field::AdvanceRoute(Block* mouseOnBlock)
{
	if (_remainDistance <= 0 || mouseOnBlock->GetBlockOnObject()->GetFurniture() != nullptr) return;

	_pickedBlock = mouseOnBlock;
	_pickedBlock->SetPassedFlg(true);
	_routeBlockArray.push_back(_pickedBlock);
	_remainDistance--;

	if (_pickedBlock->GetBlockOnObject()->GetAccessories() != nullptr)
	{
		if (_pickedBlock->GetBlockOnObject()->GetAccessories()->GetType() == ACCESSORIES_TYPE::ITEM)
		{
			_recoveryDifferentialArray.push_back(_maxDistance - _remainDistance);
			_remainDistance += _maxDistance - _remainDistance;
			_pickedBlock->GetBlockOnObject()->HiddenAccessoriesFlg(true);
		}
	}

	_fieldUI.SetCurrentEnergyValue(_remainDistance);
}

//�����߂�
void Field::BackRoute(Block* mouseOnBlock)
{
	//2�ȏ�̃u���b�N�������Ă��鎞�ɁA1�O�ɉ������u���b�N���������A
	//1���������Ă��Ȃ����ɁA�O��̍Ō�ɉ������u���b�N�������Ί����߂�
	if (_routeBlockArray.size() == 1 && mouseOnBlock != _lastDistanceBlock) return;
	else if (_routeBlockArray.size() >= 2 && _routeBlockArray[_routeBlockArray.size() - 2] != mouseOnBlock) return;
	//[_routeBlockArray.size() - 2]��1�O�ɉ������u���b�N�̗v�f��\��

	//�����߂�����
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
	_remainDistance++;
	_fieldUI.SetCurrentEnergyValue(_remainDistance);
}

//���͏I��
void Field::EndOfPassed()
{
	if (_routeBlockArray.size() <= 0) return;

	_operateDoll.SetRouteBlockArray(_routeBlockArray);
	_lastDistanceBlock = _routeBlockArray.back();
	_routeBlockArray.clear();
	_recoveryDifferentialArray.clear();
}

void Field::EndMoveDoll()
{
	//�Q�[���N���A
	if (_dustDumpValue <= 0 && _waterDumpValue <= 0)
	{
		_endGameProcess.SetCurrentProcess(ProcessType::GameClear);
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StageClear();
		return;
	}
	//�Q�[���I�[�o�[
	if (_remainDistance <= 0)
	{
		GameOver();
	}
}

void Field::SetDollOnBlockNumber(Block* dollOnBlock) {
	_blockManager.SetDollOnBlock(dollOnBlock);
}

void Field::CleanDust()
{
	_dustDumpValue--;
	_fieldUI.CleanDust();
}

void Field::CleanWater()
{
	_waterDumpValue--;
	_fieldUI.CleanWater();
}

void Field::ReSetStage()
{
	ReLoad();
}

void Field::GameOver()
{
	_endGameProcess.SetCurrentProcess(ProcessType::GameOver);
}

void Field::Render()
{
	_blockManager.Render();
	_fieldUI.Render();
	_endGameProcess.Render();
}

void Field::Release()
{
	_blockManager.Release();
	_operateDoll.Release();
	_doll.Release();
	_fieldUI.Release();
	_endGameProcess.Release();
}
