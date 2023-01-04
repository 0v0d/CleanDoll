#pragma once
#include	"Mof.h"
#include	"IBaseSetting.h"
#include	"SceneManager.h"
#include	"Button.h"

class BackSceneSetting :public IBaseSetting
{
private:
	bool* _openBackSceneSetting;
	bool* _openMenu;
	Button _closeButton, _backButton;
	CTexture _closeTexture, _backTexture;
	SCENE_TYPE _backScene;
	CSoundBuffer _buttonSe;

public:
	void Initialize();
	void SetOpenMenu(bool* openMenu) { _openMenu = openMenu; }
	void SetOpenSetting(bool* openSetting) { _openBackSceneSetting = openSetting; }

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void SetBackScene(SCENE_TYPE backScene);

	void Render();
	void Release();
private:
	void CreateButton(Button*, Vector2 pos, CTexture*, std::function<void()> callMethod);
};