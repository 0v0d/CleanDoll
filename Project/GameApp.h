#pragma once
#include	"Mof.h"

class CGameApp : public CSingleGameApplication
{
public:
	CGameApp(){}
	virtual ~CGameApp(){	Release();	}
	virtual MofBool Initialize();
	virtual MofBool Update();
	virtual MofBool Render();
	virtual MofBool Release();
};
