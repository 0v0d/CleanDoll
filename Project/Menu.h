#pragma once
#include	"Mof.h"
#include	"InputMenu.h"
#include	"SettingManager.h"
#include	"Slider.h"

class Menu
{
private:
	InputMenu _inputMenu;
	SettingManager _settingManager;
public:
	void Initialize();
	void Update();
	bool IsOpenMenu() { return _settingManager.IsOpenMenu(); }
	void Render();
	void Release();
};