#pragma once
#include "Button.h"
#include	"Mof.h"

class OpenSetting
{
private:
	Vector2 _openSettingPosition, _size;
	CRectangle _openSettingButton;
	Button _openButton;
	CTexture _openButtonTexture;
public:
	void Initialize();
	bool CheckPushButton(Vector2 mousePos) { return _openButton.CheckOnButton(mousePos); }
	void Render();
	void Release();
};