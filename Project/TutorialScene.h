#pragma once
#include "ContactFile.h"
class TutorialScene
{
private:
	bool _clear = false;
	ContactFile _contactFile;
	int _routeValue, _routeSize;
	std::pair<int, int>* _tutorialRouteArray;
	int* _inputLimitArray;
	int _inputLimitValue;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	
	std::pair<int, int>**GetTutorialRouteArray() { return &_tutorialRouteArray; }
	std::pair<int,int>* GetTutorialRoute() { return _tutorialRouteArray; }
	int GetRouteValue() const{ return _routeValue; }
	
private:
	void LoadTutorialRoute();
	void LoadInputLimit();
	void LoadTexture();
};
