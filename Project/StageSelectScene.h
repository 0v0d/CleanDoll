#pragma once
#include	"IBaseScene.h"
#include	"GetDataFromFile.h"
#include	"InputStageSelect.h"
#include	"BarManager.h"
#include	"Slider.h"
#include	"BackGround.h"
#include	"StageSelectDialog.h"
#include    "StageSelectBackGround.h"
#include	"StageSelectSceneBGM.h"
class StageSelectScene :public IBaseScene
{
private:
	StageSelectSceneBGM _stageSelectSceneBGM;
	GetDataFromFile _getDataFromFile;
	InputStageSelect _inputInStageSelect;
	BarManager _barManager;
	Slider _slider;
	StageSelectBackGround _StSelectbackGround;
	CTexture _barTexture;
	CTexture _buttonTexture;
	CTexture _stageBackTexture;
	CRectangle _stageBackRect;

	StageSelectDialog _stageSelectDialog;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void StartNextStage() { _barManager.StartNextStage(); }
	void StageClear() { _barManager.StageClear(); }
	void Render();
	void Release();
	void StopBGM();
	GetDataFromFile* GetGetDataFromFile() { return &_getDataFromFile; }
private:
	void Load();
};