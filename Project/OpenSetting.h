#pragma once
#include "Button.h"
#include "Mof.h"

class OpenSetting
{
private:
	Vector2 _openSettingPosition, _size;
	CRectangle _openSettingButton;
	Button _openButton;
	CTexture _openButtonTexture;
	Vector2 _mousePos;
public:
	void Initialize();
	bool CheckPullButton() { return _openButton.IsPullButton(); }

	void SetMousePos(Vector2);
	void Push();
	void Pull();

	void Render();
	void Release();
};