#pragma once
#include	"Mof.h"
#include	"Menu.h"
class Input
{
	Menu* _menu;
	Vector2 _mousePos;
public:
	void SetMenu(Menu* menu) { _menu = menu; }
	void Update();

private:
	void InputMouse();
};