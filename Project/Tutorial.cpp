#include "Tutorial.h"

void Tutorial::Initialize(){
	_end = _start = false;
	LoadTutorialRoute();
	LoadInputLimit();
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

void Tutorial::EndOfPassed(int routeVal) {
	int val = 0;
	for (int i = 0;i < _currentLimitNumber;i++) {
		val += _inputLimitArray[i];
	}

	_currentRouteValue += routeVal;
	if (_currentRouteValue - val >= _inputLimitArray[_currentLimitNumber]) {
		_currentLimitNumber++;
	}
}


void Tutorial::ReLoad() {
	if (!_start) _start = true;
	else _end = true;
}

void Tutorial::EndMoveDoll() {
	if (_currentLimitNumber >= _inputLimitValue) {
		_end = true;
	}
}

bool Tutorial::CheckInTutorialRoute(Block* mouseOnBlock, int routeNumber) {
	int val = _inputLimitArray[0];
	for (int i = 0;i < _currentLimitNumber;i++) {
		val += _inputLimitArray[i];
	}
	if (_currentRouteValue + routeNumber >= val) return false;

	return mouseOnBlock == _blockManager->GetBlock(_tutorialRouteArray[_currentRouteValue + routeNumber].first, _tutorialRouteArray[_currentRouteValue + routeNumber].second);
}

void Tutorial::Release(){
	delete[] _tutorialRouteArray;
	delete[] _inputLimitArray;
}
