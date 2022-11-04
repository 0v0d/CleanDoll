#pragma once
#include "Button.h"
class ReturnStageSelect
{
private:
	Vector2 _pos;
	Vector2 _size;
	Button _button;
public:
	void Initialize();
	void Render();
	void Release();
	bool CheckOnMouse(Vector2 mousePos) { return _button.CheckPushButton(mousePos); }
private:
	void TextureLoad();
};

