#pragma once
#include	"Mof.h"
#include	"SettingManager.h"
class InputMenu
{
	Vector2 _mousePos;
	SettingManager* _settingManager;
public:
	void SetSettingManager(SettingManager* settingManager) { _settingManager = settingManager; }
	void Update();
};