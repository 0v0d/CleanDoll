#include "Tutorial.h"

void Tutorial::Initialize(){
	LoadTutorialRoute();
	LoadInputLimit();
	LoadTexture();
	LoadTexturePos();
	LoadTextureHidden();
}

void Tutorial::ReLoad() {
	_end = false;
	_currentClick = 0;
	_hidden = false;

	_currentRouteValue = 0;
	_currentLimitNumber = 0;
	_currentHidden = 0;
}

void Tutorial::LoadTutorialRoute(){
	_contactFile.OpenFile("tutorialRoute.txt");
	_maxRouteValue = _contactFile.GetValue(true);
	_tutorialRouteArray = new std::pair<int, int>[_maxRouteValue];

	for (int i = 0; i < _maxRouteValue; i++){
		_tutorialRouteArray[i].first = _contactFile.GetValue(false);
		_tutorialRouteArray[i].second = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void Tutorial::LoadInputLimit()
{
	_contactFile.OpenFile("InputLimit.txt");
	int inputLimitValue = _contactFile.GetValue(true);
	_inputLimitArray = new int[inputLimitValue];
	for (int i = 0; i < inputLimitValue; i++) {
		_inputLimitArray[i] = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void Tutorial::LoadTexture()
{
	_contactFile.OpenFile("TutorialTexture.txt");
	_textureValue = _contactFile.GetValue(true);
	_tutorialTexureArray = new CTexture[_textureValue];
	for (int i = 0; i < _textureValue; i++)
	{
		_tutorialTexureArray[i].Load(_trimstring.TrimString(_contactFile.GetString(false)).c_str());
	}
	_contactFile.CloseFile();
}

void Tutorial::LoadTexturePos()
{
	_contactFile.OpenFile("tutorialTexturePos.txt");
	int texturePosValue = _contactFile.GetValue(true);
	_texturePosArray = new Vector2[texturePosValue];

	for (int i = 0; i < texturePosValue; i++) {
		_texturePosArray[i].x = _contactFile.GetValue(false);
		_texturePosArray[i].y = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void Tutorial::LoadTextureHidden()
{
	_contactFile.OpenFile("tutorialHiddenValue.txt");
	int textureHiddenValue = _contactFile.GetValue(true);
	_textureHiddenArray = new int[textureHiddenValue];

	for (int i = 0; i < textureHiddenValue; i++) {
		_textureHiddenArray[i] = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}


void Tutorial::Push() {
	if (!_hidden) {
		_currentClick++;
		if (_currentClick >= _textureValue - 1) {
			_end = true;
			_currentClick = _textureValue - 1;
			_hidden = true;

			_endGameProcess->SetCurrentProcess(ProcessType::EndTutorial);
		}
	}

	if (_currentClick == _textureHiddenArray[_currentHidden]) {
		_hidden = true;
		_currentHidden++;
	}

}

void Tutorial::EndOfPassed(int routeVal) {

	_currentRouteValue += routeVal;
}

void Tutorial::EndMoveDoll() {

	if (_currentRouteValue - CalcuCurrentLimitValue() >= _inputLimitArray[_currentLimitNumber]) {
		_hidden = false;
		_currentLimitNumber++;
	}
}

bool Tutorial::CheckInTutorialRoute(Block* mouseOnBlock, int routeNumber) {
	int val = CalcuCurrentLimitValue() + _inputLimitArray[_currentLimitNumber];
	if (_currentRouteValue + routeNumber >= val) return false;

	return mouseOnBlock == _blockManager->GetBlock(_tutorialRouteArray[_currentRouteValue + routeNumber].first,
		_tutorialRouteArray[_currentRouteValue + routeNumber].second);
}

int Tutorial::CalcuCurrentLimitValue() {
	int val = 0;
	for (int i = 0; i < _currentLimitNumber; i++) {
		val += _inputLimitArray[i];
	}
	return val;
}


void Tutorial::Render()
{
	if (!_hidden)
		_tutorialTexureArray[_currentClick].Render(_texturePosArray[_currentClick].x, _texturePosArray[_currentClick].y);
}

void Tutorial::Release(){
	delete[] _tutorialRouteArray;
	delete[] _inputLimitArray;
	delete[] _tutorialTexureArray;
	delete[] _texturePosArray;
	delete[] _textureHiddenArray;
}
