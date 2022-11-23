#pragma once
#include	"Mof.h"
#include	"IBaseSetting.h"
#include	"SceneManager.h"


class BackSceneSetting :public IBaseSetting
{
private:
	bool* _openBackSceneSetting;
	bool* _openMenu;
	CRectangle _closeButton, _backButton;
	SCENE_TYPE _backScene;

public:
	void Initialize();
	void SetOpenMenu(bool* openMenu) { _openMenu = openMenu; }
	void SetOpenSetting(bool* openSetting) { _openBackSceneSetting = openSetting; }

	void Update();
	void Push(Vector2 mousePos);
	void Pull(Vector2 mousePos);
	void SetBackScene(SCENE_TYPE backScene);

	void Render();
	void Release();
private:
	void PushButton(Vector2 mousePos);
};