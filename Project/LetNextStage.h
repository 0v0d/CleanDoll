#pragma once
#include "Button.h"

class LetNextStage
{
private:
	Vector2 _pos = Vector2(200, 60);
	Vector2 _size = Vector2(200, 60);
	Button _button;
	Vector2 _mousePos;
public:
	void Initialize();
	void Render();
	void Release();
	bool CheckOnMouse(Vector2 mousePos) { return _button.CheckPushButton(mousePos); }
private:
	void TextureLoad();
};

