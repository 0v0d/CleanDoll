#pragma once
#include	"Mof.h"
#include	"map"
#include	"Button.h"
#include	"IBaseSetting.h"

class SetUpSetting
{
private:
	bool _openSetting;
	bool* _openMenu;
	IBaseSetting* _currentSetting = nullptr;
	std::map<Button*, IBaseSetting*> _buttonArray;
	Button _audioButton, _backSceneButton, _closeMenuButton;
	CTexture _audioButtonTexure;
	CTexture _backSceneTexture;
	CTexture _closeMenuTexture;
public:
	void Initialize();
	void SetOpenMenu(bool* openMenu) { _openMenu = openMenu; }
	void Update();
	void Push(Vector2 mousePos);
	void Render();
	void Release();
	void Pull(Vector2 mousePos);
};