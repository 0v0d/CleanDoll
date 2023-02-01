#pragma once
#include	"Mof.h"
#include	"RemainingIcon.h"
#include	"map"
#include	"Number.h"
#include	"SlideInUI.h"

class RemainingDumpUI
{
	enum ICON_TYPE {
		DUST,
		WATER,
	};

	Number* _remainingValue;
	SlideInUI _slideInUI;
	int _dustValue, _waterValue;
	CTexture _baseTexture, _markTexture, _notExistTexture;
	CTexture _dustIconTexture, _waterIconTexture;
	CTexture _coinIconTexture, _getcoinIconTexture;
	CTexture _numberTexture;
	Vector2 _basePosition;
	std::map<ICON_TYPE, RemainingIcon*> _iconArray;
	float _scale, _objectiveSizeX;
	float _getCoinScale;
	const int _iconValue = 2;
	bool _getCoin;
	const int _numberValue = 10;
	const float _numberScale = 0.05f;
public:
	RemainingDumpUI();
	~RemainingDumpUI();
	void Initialize();
	void ReLoad();
	void StartSlideInUI();
	
	void Update();
	void SetDustValue(int dumpValue);
	void SetWaterValue(int dumpValue);
	void GetCoin(){ _getCoin = true; }
	void CleanDust();
	void CleanWater();

	void Render();
	void Release();

private:
	void MarkIcon(ICON_TYPE);
	void LoadTexture();
	void IconSetTexture(ICON_TYPE, CTexture*);
	void CalcuScale();
	bool CheckLostDump(int dumpValue) { return dumpValue <= 0; }
};