#pragma once
#include	"Mof.h"
#include	"SettingManager.h"

class Menu
{
	SettingManager _settingManager;
public:
	void Initialize();
	void Update();
	void SetMousePos(Vector2 pos);
	void Push();
	void Pull();

	void Render();
	void Release();

	bool IsOpenMenu() { return _settingManager.IsOpenMenu(); }
};