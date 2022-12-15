#pragma once
#include "ContactFile.h"
class TutorialScene
{
private:
	bool _clear = false;
	ContactFile _contactFile;
	int _routeValue, _routeSize;
	std::pair<int, int>* _tutorialRouteArray;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	
	std::pair<int, int>**GetTutorialRouteArray() { return &_tutorialRouteArray; }
	std::pair<int,int>* GetTutorialRoute() { return _tutorialRouteArray; }
	int GetRouteValue() const{ return _routeValue; }
	void SetRouteClear(bool flg) { _clear = flg; }
	bool IsClear() { return _clear; }
	bool Clear()
	{
		if (!_clear)
		{
			return true;
		}
	}
	void LoadTutorialRoute();
private:
	void LoadTexture();
	
};
