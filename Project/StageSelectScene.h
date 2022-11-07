#pragma once
#include	"IBaseScene.h"
#include	"GetDataFromFile.h"
#include	"InputStageSelect.h"
#include	"BarManager.h"
#include	"Slider.h"
#include	"Menu.h"

class StageSelectScene :public IBaseScene
{
private:
	GetDataFromFile _getDataFromFile;
	InputStageSelect _inputInStageSelect;
	BarManager _barManager;
	Slider _slider;
	Menu* _menu;
	CTexture _barTexture;
	CTexture _buttonTexture;
public:
	void SetMenu(Menu* menu) { _menu = menu; }
	void Initialize();
	void ReLoad();
	void Update();
	void StartNextStage() { _barManager.StartNextStage(); }
	void Render();
	void Release();
	GetDataFromFile* GetGetDataFromFile() { return &_getDataFromFile; }
};