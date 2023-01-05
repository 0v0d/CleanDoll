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
	Button _audioButton, _dollButton, _backSceneButton, _closeMenuButton;
	CTexture _audioButtonTexure;
	CTexture _dollButtonTexture;
	CTexture _backTitleSceneTexture, _backSelectSceneTexture;
	CTexture _closeMenuTexture;

	Vector2 _mousePos;

public:
	void Initialize();
	void SetOpenMenu(bool* openMenu) { _openMenu = openMenu; }

	void Update();
	void SetMousePos(Vector2 mousePos);
	void Push();
	void Pull();
	//現在のシーンから戻るシーンを決める
	void DetermineBackScene();

	void Render();
	void Release();

private:
	void LoadTexture();
	void CheckPullButton();
};