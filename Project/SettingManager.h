#pragma once
#include	"SetUpSetting.h"
#include	"OpenSetting.h"

class SettingManager
{
	bool _openMenu;
	Vector2 _mousePos;
	SetUpSetting _setUpSetting;
	OpenSetting _openSettingButton;
	CTexture _menuTexture;
public:
	void Initialize();
	void Update();
	void SetMousePos(Vector2 mousePos);
	void Push();
	void Pull();

	void Render();
	void Release();

	bool IsOpenMenu() { return _openMenu; }
};