#include "TutorialScene.h"

void TutorialScene::Initialize()
{
	_clear = false;
	LoadTutorialRoute();
}

void TutorialScene::LoadTutorialRoute()
{
	_contactFile.OpenFile("tutorialRoute.txt");
	int index = _contactFile.GetValue(true);
	_tutorialRouteArray = new std::pair<int, int>[index];

	for (int i = 0; i < index; i++)
	{
		_tutorialRouteArray[i].first = _contactFile.GetValue(false);
		_tutorialRouteArray[i].second = _contactFile.GetValue(false);
	}
	_contactFile.CloseFile();
}

void TutorialScene::Update()
{

}

void TutorialScene::Render()
{

}

void TutorialScene::Release()
{
	
	delete[] _tutorialRouteArray;
}

void TutorialScene::LoadTexture()
{

}
