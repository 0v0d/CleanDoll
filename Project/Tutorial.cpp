#include "Tutorial.h"

void Tutorial::Initialize(){
	_end = _start = false;
	LoadTutorialRoute();
	LoadInputLimit();
	LoadTexture();
	LoadTexturePos();
	LoadTexureHidden();
	_currentClick = 0;
	_hidden = false;
}

void Tutorial::ReLoad() {
	if (!_start) _start = true;
	else _end = true;
}

void Tutorial::Push()
{
	if (!_hidden){
		_currentClick++;
		if(_currentClick >=_textureValue-1){
			_currentClick = _textureValue - 1;
			_hidden = true;
		}
	}

	if(_currentClick == _textureHiddenArray[_currentHidden]){
		_hidden = true;
		_currentHidden++;
	}
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
	_inputLimitValue = _contactFile.GetValue(true);
	_inputLimitArray = new int[_inputLimitValue];
	for (int i = 0; i < _inputLimitValue; i++) {
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
	_texturePosValue = _contactFile.GetValue(true);
	_texturePosArray = new std::pair<int, int>[_texturePosValue];

	for (int i = 0; i < _texturePosValue; i++) {
		_texturePosArray[i].first = _contactFile.GetValue(false);
		_texturePosArray[i].second = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void Tutorial::LoadTexureHidden()
{
	_contactFile.OpenFile("tutorialHiddenValue.txt");
	_textureHiddenValue = _contactFile.GetValue(true);
	_textureHiddenArray = new int[_textureHiddenValue];

	for (int i = 0; i < _textureHiddenValue; i++) {
		_textureHiddenArray[i] = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void Tutorial::EndOfPassed(int routeVal) {

	_currentRouteValue += routeVal;
}

void Tutorial::EndMoveDoll() {
	int val = 0;
	for (int i = 0; i < _currentLimitNumber; i++) {
		val += _inputLimitArray[i];
	}

	if (_currentRouteValue - val >= _inputLimitArray[_currentLimitNumber]) {
		_hidden = false;
		_currentLimitNumber++;
	}

	if (_currentLimitNumber >= _inputLimitValue) {
		_end = true;
	}
}

bool Tutorial::CheckInTutorialRoute(Block* mouseOnBlock, int routeNumber) {
	int val = 0;
	for (int i = 0; i < _currentLimitNumber + 1; i++) {
		val += _inputLimitArray[i];
	}
	if (_currentRouteValue + routeNumber >= val) return false;

	return mouseOnBlock == _blockManager->GetBlock(_tutorialRouteArray[_currentRouteValue + routeNumber].first,
		_tutorialRouteArray[_currentRouteValue + routeNumber].second);
}

void Tutorial::Render()
{
	if (!_hidden)
		_tutorialTexureArray[_currentClick].Render(_texturePosArray[_currentClick].first, _texturePosArray[_currentClick].second);
}

void Tutorial::Release(){
	delete[] _tutorialRouteArray;
	delete[] _inputLimitArray;
	delete[] _tutorialTexureArray;
	delete[] _texturePosArray;
	delete[] _textureHiddenArray;
}
