#pragma once
#include	"Mof.h"
#include	"Menu.h"
#include	"Input.h"

class CGameApp : public CSingleGameApplication
{
	Input _input;
	Menu _menu;
public:
	CGameApp(){}
	virtual ~CGameApp(){	Release();	}
	virtual MofBool Initialize();
	virtual MofBool Update();
	virtual MofBool Render();
	virtual MofBool Release();
};
