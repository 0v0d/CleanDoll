#pragma once
#include	"Mof.h"
#include	"IBaseSetting.h"
class BackSceneSetting :public IBaseSetting
{
	bool* _openBackSceneSetting;
	CRectangle _closeButton;

public:
	void Initialize();
	void Update();
	void SetOpenSetting(bool* openSetting) { _openBackSceneSetting = openSetting; }
	void Push(Vector2 mousePos);
	void Pull(Vector2 mousePos);
	void Render();
	void Release();

private:
	void PushButton(Vector2 mousePos);
};