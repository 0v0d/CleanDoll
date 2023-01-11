#pragma once
#include	"Mof.h"
#include	"Menu.h"
#include	"Input.h"
#include	"ExitGame.h"

class CGameApp : public CSingleGameApplication
{
	Input _input;
	Menu _menu;
	ExitGame _exit;

public:
	CGameApp(){}
	virtual ~CGameApp(){	Release();	}
	virtual MofBool Initialize();
	virtual MofBool Update();
	virtual MofBool Render();
	virtual MofBool Release();
	ExitGame* GetExitGame() { return &_exit; }
};
