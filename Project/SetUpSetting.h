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
	CTexture _backTitleSceneTexture, _backSelectSceneTexture;
	CTexture _closeMenuTexture;

public:
	void Initialize();
	void SetOpenMenu(bool* openMenu) { _openMenu = openMenu; }

	void Update();
	void Push(Vector2 mousePos);
	void Pull(Vector2 mousePos);
	void DetermineBackScene();

	void Render();
	void Release();

private:
	void LoadTexture();
};