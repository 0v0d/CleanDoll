#include "Field.h"
#include "SceneManager.h"
#include "StageSelectScene.h"
#include "GalleryScene.h"

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
	_tutorial.Initialize();

	_doll.SetDumpValue(_dustDumpValue, _waterDumpValue);
	_tutorial.SetBlockManager(&_blockManager);
}

void Field::ReLoad()
{
	_blockManager.ReLoad();
	_doll.ReLoad();
	_fieldUI.ReLoad();
	_operateDoll.ReLoad();
	_tutorial.ReLoad();
	
	_doll.CalcuScale(_blockManager.GetDollOnBlock()->GetBlockSize().y, _blockManager.GetScale());
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
	_fieldUI.SetDustDumpValue(_initalDustValue);
	_fieldUI.SetWaterDumpValue(_initalWaterValue);
	if (_getCoin)_fieldUI.GettedGalleryCoin();

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
	if(_tutorial.IsHideen())
	{
		if (_push) {
			PassedMouse(_mousePos);
		}
	}

	
	_blockManager.Update();
	_doll.Update();
	_endGameProcess.Update();
	_fieldUI.Update();
}

void Field::SetMousePos(Vector2 mousePos){
	_mousePos = mousePos;
	_endGameProcess.SetMousePos(mousePos);
}

void Field::Push() {
	_push = true;
	_endGameProcess.Push();
	_tutorial.Push();
}

void Field::Pull() {
	_push = false;
	EndOfPassed();
	_endGameProcess.Pull();
}

//ブロックを押したとき
void Field::PassedMouse(Vector2 mousePosition)
{
	if (*_onMoveDoll) return;

	Block* mouseOnBlock = _blockManager.GetMouseOnBlock(mousePosition);
	if (mouseOnBlock == nullptr) return;

	for (int i = 0; i < _adjoinBlockValue; i++)
	{
		if (mouseOnBlock != _pickedBlock->GetAdjoinBlockArray()[i])continue;
		//押されていないブロックを押したとき、押したブロックを記録
		if (!mouseOnBlock->IsPassed())
		{
			AdvanceRoute(mouseOnBlock);
		}
		//1回以上入力していて、既に押されているブロックを押したとき、巻き戻し
		else if (_routeBlockArray.size() > 0)
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
	if (!_tutorial.IsEnd() && !_tutorial.CheckInTutorialRoute(mouseOnBlock, _routeBlockArray.size())) return;

	_pickedBlock = mouseOnBlock;
	_routeBlockArray.push_back(_pickedBlock);
	_pickedBlock->SetPassedFlg(true);
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

//巻き戻し
void Field::BackRoute(Block* mouseOnBlock)
{
	//2つ以上のブロックを押している時に、1つ前に押したブロックを押すか、
	//1つしか押していない時に、前回の最後に押したブロックを押せば巻き戻す
	if (_routeBlockArray.size() == 1 && mouseOnBlock != _lastDistanceBlock) return;
	else if (_routeBlockArray.size() >= 2 && _routeBlockArray[_routeBlockArray.size() - 2] != mouseOnBlock) return;
	//[_routeBlockArray.size() - 2]は1つ前に押したブロックの要素を表す

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
	_remainDistance++;
	_fieldUI.SetCurrentEnergyValue(_remainDistance);
}

//入力終了
void Field::EndOfPassed(){
	if (_routeBlockArray.size() <= 0) return;

	if(!_tutorial.IsEnd()){
		_tutorial.EndOfPassed(_routeBlockArray.size());
	}

	_operateDoll.SetRouteBlockArray(_routeBlockArray);
	_lastDistanceBlock = _routeBlockArray.back();
	_routeBlockArray.clear();
	_recoveryDifferentialArray.clear();
}

void Field::EndMoveDoll(){

	//if (_tutorial.IsEnd()) {
	//	StageSelectScene* stageSelect = dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT));
	//	_endGameProcess.SetCurrentProcess(ProcessType::EndTutorial);
	//}
	if (!_tutorial.IsEnd()) {
		_tutorial.EndMoveDoll();
	}
	
	else
	{
		//ゲームクリア
		if (_dustDumpValue <= 0 && _waterDumpValue <= 0) {

			StageSelectScene* stageSelect=dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT));
			_endGameProcess.SetCurrentProcess(ProcessType::GameClear);
			stageSelect->StageClear();
			
			if (_doll.IsGetCoin()) {
				if (!_getCoin) {
					dynamic_cast<GalleryScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::GALLERY))->AddCoin();
					stageSelect->GetCoin();
					_getCoin = true;
				}
			}
			return;
		}
		//ゲームオーバー
		if (_remainDistance <= 0) {
			GameOver();
		}
		if (CheckCantMoveDoll()) {
			GameOver();
		}
	}
}

void Field::SetDollOnBlockNumber(Block* dollOnBlock) {
	_blockManager.SetDollOnBlock(dollOnBlock);
}

void Field::GetCoin() {
	if (_getCoin) return;
	_fieldUI.GetGalleryCoin();
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

bool Field::CheckCantMoveDoll() {
	Block** adjoinBlockArray = _blockManager.GetDollOnBlock()->GetAdjoinBlockArray();

	for (int i = 0;i < _adjoinBlockValue;i++) {
		if (adjoinBlockArray[i] == nullptr) continue;
		if (!adjoinBlockArray[i]->IsPassed() && adjoinBlockArray[i]->GetBlockOnObject()->GetFurniture() == nullptr) {
			return false;
		}
	}
	return true;
}


void Field::Render()
{
	_blockManager.Render();
	_fieldUI.Render();
	_endGameProcess.Render();
	_tutorial.Render();
}

void Field::Release()
{
	_blockManager.Release();
	_operateDoll.Release();
	_doll.Release();
	_fieldUI.Release();
	_endGameProcess.Release();
	_tutorial.Release();
}