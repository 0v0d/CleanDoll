#pragma once
#include	"Mof.h"
#include	"RemainingIcon.h"
#include	"map"
#include "RemainingValue.h"

enum ICON_TYPE {
	DUST,
	WATER,
};

class RemainingDumpUI
{
	RemainingValue _remainingDustValue, _remainingWaterValue;
	int _dustValue, _waterValue;
	CTexture _baseTexture, _markTexture, _notExistTexture;
	CTexture _dustIconTexture, _waterIconTexture, _coinIconTexture;
	CTexture _numTexture;
	Vector2 _basePosition;
	std::map<ICON_TYPE, RemainingIcon*> _iconArray;
	float _scale, _objectiveSizeX;
	const int _iconValue = 2;
	
public:
	void Initialize();
	void ReLoad();
	
	void Update();
	void SetDustValue(int dumpValue);
	void SetWaterValue(int dumpValue);
	void GettedCoin();
	void CleanDust();
	void CleanWater();
	void MarkIcon(ICON_TYPE);


	void Render();
	void Release();

private:
	void LoadTexture();
	void IconSetTexture(ICON_TYPE, CTexture*);
	void CalcuScale();
	bool CheckLostDump(int dumpValue) { return dumpValue <= 0; }
};