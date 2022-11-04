#pragma once
#include "Button.h"
class RetryGame
{
private:
	Vector2 _pos;
	Vector2 _size;
	Button _button;
public:
	void Initialize();
	void Render();
	void Release();
	void ClickButton(Vector2 mousePos);
private:
	void TextureLoad();
};

