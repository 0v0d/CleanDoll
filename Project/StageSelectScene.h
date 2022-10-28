#pragma once
#include	"IBaseScene.h"
#include	"GetDataFromFile.h"
#include	"InputStageSelect.h"
#include	"BarManager.h"
#include	"Slider.h"
#include	"Menu.h"

class StageSelectScene :public IBaseScene
{
	GetDataFromFile _getDataFromFile;
	InputStageSelect _inputInStageSelect;
	BarManager _barManager;
	Slider _slider;
	Menu* _menu;

public:
	void SetMenu(Menu* menu) { _menu = menu; }
	void Initialize();
	void ReLoad();
	
	void Update();
	
	void Render();
	void Release();

	GetDataFromFile* GetGetDataFromFile() { return &_getDataFromFile; }
};