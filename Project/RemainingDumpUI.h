#pragma once
#include	"Mof.h"
#include	"RemainingIcon.h"

class RemainingDumpUI
{
	int _dustValue, _waterValue;
	CTexture _baseTexture, _markTexture, _notExistTexture;
	CTexture _dustIconTexture, _waterIconTexture, _coinIconTexture;
	Vector2 _basePosition;
	const int _iconValue = 3;
	RemainingIcon* _iconArray;
	float _scale, _objectiveSizeX;
public:
	void Initialize();
	void ReLoad();
	void SetDumpValue(int dustValue, int waterValue);
	void CleanDust();
	void CleanWater();
	void Render();
	void Release();

private:
	void LoadTexture();
	void CalcuScale();
	bool CheckLostDump(int dumpValue) { return dumpValue <= 0; }
	void MarkIcon(int);
};