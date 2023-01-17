#pragma once
#include "Mof.h"
#include "IBaseEndGameProcess.h"
#include "GameClearBackGround.h"
#include "EndTutorialDollAnimation.h"
#include "GameClearLogoAnimation.h"
#include	"EndGameButtonManager.h"

class EndTutorial :public IBaseEndGameProcess
{
	CTexture _stageSelectTexture;
	EndGameButtonManager _endGameButtonManager;
	GameClearLogoAnimation _logoAnim;
	EndTutorialDollAnimation _dollAnim;
	GameClearBackGround _backGroundAnim;
public:
	void Initialize();
	void ReLoad();

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void Render();
	void Release();
private:
	void LoadTexture();
	void CreateButtonArray();
	void UpdateAnimation();
};