#pragma once
#include "Mof.h"
#include "GameApp.h"
#include "ExitGame.h"


class CWindowProc : public CDefWindowProc
{
	ExitGame* _exitGame;
public:
	CWindowProc();
	virtual ~CWindowProc();
	virtual MofProcResult WindowProc(MofWindowHandle hWnd, MofUInt msg, MofProcParamW wpar, MofProcParamL lpar);
	void SetExitGame(ExitGame* exitgame) { _exitGame = exitgame; }

};