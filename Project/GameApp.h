#pragma once
#include	"Mof.h"
#include	"Menu.h"

class CGameApp : public CSingleGameApplication
{
	Menu _menu;
public:
	CGameApp(){}
	virtual ~CGameApp(){	Release();	}
	virtual MofBool Initialize();
	virtual MofBool Update();
	virtual MofBool Render();
	virtual MofBool Release();
};
