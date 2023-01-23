#include "Field.h"
#include "SceneManager.h"
#include "StageSelectScene.h"
#include "GalleryScene.h"

void Field::Initialize()
{
	LoadTexture();
	LoadSound();
	CreateButton();
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
	_clearletter.Initialize();

	_pushReset = true;

}

void Field::LoadTexture()
{
	_clearButtonTexture.Load("clearButton.png");
}

void Field::LoadSound() {
	_buttonSe.Load("ClicktoStart.mp3");
}

void Field::CreateButton()
{
	_clearButton.SetTexture(&_clearButtonTexture);
	_clearButton.SetPosition(Vector2(_clearButtonTexture.GetWidth(), _clearButtonTexture.GetHeight() / 3));
	_clearButton.SetSeSound(&_buttonSe);
	_clearButton.SetStatu(false, true, [&]() {GameClear(); });
}

void Field::ReLoad()
{
	ReSetStage();
	if(_tutorial.IsEnd()) _fieldUI.StartSlideInUI();
}

void Field::ReSetStage() {

	_blockManager.ReLoad();
	_doll.ReLoad();
	_fieldUI.ReLoad();
	_operateDoll.ReLoad();
	if (!_tutorial.IsEnd()) {
		if (_pushReset) {
			_pushReset = false;
			_tutorial.ReLoad();
		}
		else {
			_tutorial.SetEnd(true);
		}
	}

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
	_fieldUI.SetDustDumpValue(_initalDustValue);
	_fieldUI.SetWaterDumpValue(_initalWaterValue);

	if (_getCoin) {
		_fieldUI.GetGalleryCoin();
		_blockManager.HiddenCoin();
	}

	_push = false;
	_pushReset = false;
	_show = false;
	_endProcess = false;
}

void Field::SetDollPosition(int x, int y)
{
	_doll.SetPosition(_blockManager.GetBlock(x, y)->GetCenterPosition());

	_dollInitialPositionX = x;
	_dollInitialPositionY = y;

	SetDollOnBlockNumber(_blockManager.GetBlock(x, y));
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
	_blockManager.Update();
	_doll.Update();
	_endGameProcess.Update();
	_fieldUI.Update();

	if (!_tutorial.IsEnd() && !_tutorial.IsHideen()) return;

	if (_push) {
		PassedMouse(_mousePos);
	}
	_clearletter.Update();
}

void Field::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	_endGameProcess.SetMousePos(mousePos);
	_clearButton.SetMousePos(mousePos);
}

void Field::Push() {
	_push = true;
	_tutorial.Push();
	_endGameProcess.Push();
	if (_show){
		_clearButton.Push();
	}
}

void Field::Pull() {
	_push = false;
	EndOfPassed();
	_endGameProcess.Pull();
	if (_show) {
		_clearButton.Pull();
	}
}

//ブロックを押したとき
void Field::PassedMouse(Vector2 mousePosition)
{
	if (*_onMoveDoll) return;

	Block* mouseOnBlock = _blockManager.GetMouseOnBlock(mousePosition);
	if (mouseOnBlock == nullptr) return;

	for (int i = 0; i < _adjoinBlockValue; i++){
		if (mouseOnBlock != _pickedBlock->GetAdjoinBlockArray()[i])continue;
		//押されていないブロックを押したとき、押したブロックを記録
		if (!mouseOnBlock->IsPassed()){
			AdvanceRoute(mouseOnBlock);
		}
		//1回以上入力していて、既に押されているブロックを押したとき、巻き戻し
		else if (_routeBlockArray.size() > 0){
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

	if (_pickedBlock->GetBlockOnObject()->GetAccessories() != nullptr){
		if (_pickedBlock->GetBlockOnObject()->GetAccessories()->GetType() == ACCESSORIES_TYPE::ITEM){
			_recoveryDifferentialArray.push_back(_maxDistance - _remainDistance);
			_remainDistance += _maxDistance - _remainDistance;
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
	if (_pickedBlock->GetBlockOnObject()->GetAccessories() != nullptr){
		if (_pickedBlock->GetBlockOnObject()->GetAccessories()->GetType() == ACCESSORIES_TYPE::ITEM){
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
void Field::EndOfPassed() {
	if (_routeBlockArray.size() <= 0) return;

	if (!_tutorial.IsEnd()) {
		_tutorial.EndOfPassed(_routeBlockArray.size());
	}

	_operateDoll.SetRouteBlockArray(_routeBlockArray);
	_lastDistanceBlock = _routeBlockArray.back();
	_routeBlockArray.clear();
	_recoveryDifferentialArray.clear();
}

void Field::EndMoveDoll() {
	if (!_tutorial.IsEnd()) {
		_tutorial.EndMoveDoll();
		if(_dustDumpValue <= 0 && _waterDumpValue <= 0){
			_show = true;
		}
	}
	else {
		//ゲームクリア
		if (_dustDumpValue <= 0 && _waterDumpValue <= 0) {
			_show = true;
			StageSelectScene* stageSelect = dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT));
			if (_remainDistance <= 0) {
				_endGameProcess.SetCurrentProcess(ProcessType::GameClear);
				stageSelect->StageClear();
				_show = false;
				_endProcess = true;
			}
			if (!_getCoin) {
				if (_doll.IsGetCoin()) {
					dynamic_cast<GalleryScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::GALLERY))->AddCoin();
					stageSelect->GetCoin();
					_getCoin = true;

					_show = false;
					_endGameProcess.SetCurrentProcess(ProcessType::GameClear);
					stageSelect->StageClear();
					_endProcess = true;
				}
			}
			else{
				_show = false;
				_endGameProcess.SetCurrentProcess(ProcessType::GameClear);
				stageSelect->StageClear();
				_endProcess = true;
			}
		}
		//ゲームオーバー
		else if (_remainDistance <= 0) {
			GameOver();
			_endProcess = true;
		}
		else if (CheckCantMoveDoll()) {
			GameOver();
			_endProcess = true;
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

void Field::CleanDust() {
	_dustDumpValue--;
	_fieldUI.CleanDust();
}

void Field::CleanWater() {
	_waterDumpValue--;
	_fieldUI.CleanWater();
}

void Field::GameClear() {
	if (!_tutorial.IsEnd()&& _show) {
		_endGameProcess.SetCurrentProcess(ProcessType::EndTutorial);
		_tutorial.SetEnd(true);
	}
	else {
		StageSelectScene* stageSelect = dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT));
		_endGameProcess.SetCurrentProcess(ProcessType::GameClear);
		stageSelect->StageClear();
	}
	_endProcess = true;
	_show = false;
}

void Field::GameOver() {
	_endGameProcess.SetCurrentProcess(ProcessType::GameOver);
}

bool Field::CheckCantMoveDoll() {
	Block** adjoinBlockArray = _blockManager.GetDollOnBlock()->GetAdjoinBlockArray();
	
	for (int i = 0; i < _adjoinBlockValue; i++) {
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
	if (_show){
		_clearButton.Render();
		_clearletter.Rnder();
	}
	_tutorial.Render();
	_endGameProcess.Render();
}

void Field::Release()
{
	_blockManager.Release();
	_operateDoll.Release();
	_doll.Release();
	_fieldUI.Release();
	_endGameProcess.Release();
	_tutorial.Release();
	_clearButtonTexture.Release();
	_buttonSe.Release();
	_clearletter.Release();
}