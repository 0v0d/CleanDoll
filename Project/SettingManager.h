#pragma once
#include	"SetUpSetting.h"
#include	"OpenSetting.h"

class SettingManager
{
private:
	bool _openMenu;

	SetUpSetting _setUpSetting;
	OpenSetting _openSettingButton;
public:
	void Initialize();
	void Update();
	void Push(Vector2 mousePos);
	void Pull(Vector2 mousePos);
	void Render();
	void Release();
	bool IsOpenMenu() { return _openMenu; }
};