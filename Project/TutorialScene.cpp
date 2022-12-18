#include "TutorialScene.h"

void TutorialScene::Initialize(){

	LoadTutorialRoute();
	LoadInputLimit();
}

void TutorialScene::LoadTutorialRoute(){
	_contactFile.OpenFile("tutorialRoute.txt");
	_routeValue = _contactFile.GetValue(true);
	_tutorialRouteArray = new std::pair<int, int>[_routeValue];

	for (int i = 0; i < _routeValue; i++){
		_tutorialRouteArray[i].first = _contactFile.GetValue(false);
		_tutorialRouteArray[i].second = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void TutorialScene::LoadInputLimit()
{
	_contactFile.OpenFile("InputLimit.txt");
	_inputLimitValue = _contactFile.GetValue(true);
	_inputLimitArray = new int[_inputLimitValue];
	for (int i = 0; i < _inputLimitValue; i++) {
		_inputLimitArray[i] = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void TutorialScene::Update(){

}

void TutorialScene::Render(){

}

void TutorialScene::Release(){
	delete[] _tutorialRouteArray;
	delete[] _inputLimitArray;
}

void TutorialScene::LoadTexture(){

}
