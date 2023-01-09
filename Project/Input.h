#pragma once
#include	"Mof.h"
#include	"Menu.h"
#include	"ExitGame.h"
class Input
{
	Menu* _menu;
	ExitGame* _exitGame;
	Vector2 _mousePos;
public:
	void SetMenu(Menu* menu) { _menu = menu; }
	void SetExitGame(ExitGame* exitGame) { _exitGame = exitGame; }
	void Update();

private:
	void InputMouse();
	void InputKey();

	void SetMousePos();
	void Push();
	void Pull();

private:
	bool CheckActionMenu();
};