#pragma once
#include	"SetUpSetting.h"
#include	"Button.h"

class SettingManager
{
	bool _openMenu;
	Vector2 _mousePos;
	SetUpSetting _setUpSetting;
	Button _openSettingButton;
	CTexture _menuTexture, _openButtonTexture;
	CSoundBuffer _buttonSe;
public:
	void Initialize();
	void Update();
	void SetMousePos(Vector2 mousePos);
	void Push();
	void Pull();

	void Render();
	void Release();

	bool IsOpenMenu() { return _openMenu; }

private:
	void CreateButton();
};