#pragma once
#include	"Mof.h"
class OpenSetting
{

	Vector2 _openSettingPosition, _size;
	CRectangle _openSettingButton;
public:
	void Initialize();
	bool CheckPushButton(Vector2 mousePos) { return _openSettingButton.CollisionPoint(mousePos); }
	void Render();
	void Release();
};