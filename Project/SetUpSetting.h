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
	bool  _openbackTitle, _openbaclSelectScene;
	
	IBaseSetting* _currentSetting = nullptr;
	std::map<Button*, IBaseSetting*> _buttonArray;
	Button _audioButton, _dollButton, _backSceneButton, _closeMenuButton;
	CTexture _audioButtonTexure;
	CTexture _dollButtonTexture;
	CTexture _backTitleSceneTexture, _backSelectSceneTexture;
	CTexture _closeMenuTexture;
	CSoundBuffer _buttonSe;
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

	bool IsOpenSetting() { return _openSetting; }

private:
	void LoadTexture();
	void CreateButton();
};