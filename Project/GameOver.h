#pragma once
#include	"Mof.h"
#include	"IBaseEndGameProcess.h"
#include	"GameOverDollAnimation.h"
#include	"EndGameButtonManager.h"
#include "GameOverAnimation.h"

class GameOver:public IBaseEndGameProcess
{
private:
	GameOverAnimation _gameOverAnimation;
	GameOverDollAnimation _dollAnim;

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
