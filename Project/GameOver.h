#pragma once
#include	"Mof.h"
#include	"IBaseEndGameProcess.h"
#include	"GameOverBackGround.h"
#include	"GameOverLogoAnimation.h"
#include	"EndGameButtonManager.h"

class GameOver:public IBaseEndGameProcess
{
private:
	GameOverBackGround _backGround;
	GameOverLogoAnimation _logoAnim;

	EndGameButtonManager _endGameButtonManager;
	CTexture _retryTexture, _stageSelectTexture;

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