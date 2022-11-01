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
	CRectangle _closeMenuButton;
	Button _audioButton, _backSceneButton;
public:
	void Initialize();
	void SetOpenMenu(bool* openMenu) { _openMenu = openMenu; }
	void Update();
	void Push(Vector2 mousePos);
	void Render();
	void Release();
private:
	bool CheckPuchButton(Vector2 mousePos, CRectangle button) { return button.CollisionPoint(mousePos); }
};