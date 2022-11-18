#pragma once
#include	"IBaseScene.h"
#include	"GetDataFromFile.h"
#include	"InputStageSelect.h"
#include	"BarManager.h"
#include	"Slider.h"
#include	"BackGround.h"

class StageSelectScene :public IBaseScene
{
private:
	GetDataFromFile _getDataFromFile;
	InputStageSelect _inputInStageSelect;
	BarManager _barManager;
	Slider _slider;
	BackGround _backGround;
	CTexture _barTexture;
	CTexture _buttonTexture;
	CTexture _stageBackTexture;
	CRectangle _stageBackRect;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void StartNextStage() { _barManager.StartNextStage(); }
	void StageClear() { _barManager.StageClear(); }
	void Render();
	void Release();
	GetDataFromFile* GetGetDataFromFile() { return &_getDataFromFile; }
private:
	void Load();
};