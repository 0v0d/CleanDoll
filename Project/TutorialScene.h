#pragma once
#include "ContactFile.h"
class TutorialScene
{
private:
	bool _clear;
	ContactFile _contactFile;
	int _routeValue, _routeSize;
	std::pair<int, int>* _tutorialRouteArray;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	bool IsClear() { return _clear; }
	std::pair<int, int>**GetTutorialRouteArray() { return &_tutorialRouteArray; }
	std::pair<int,int>* GetTutorialRoute() { return _tutorialRouteArray; }


private:
	void LoadTexture();
	void LoadTutorialRoute();
};
