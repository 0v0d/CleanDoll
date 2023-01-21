#pragma once
#include	"IBaseEndGameProcess.h"
#include	"GameClearDollAnimation.h"
#include	"EndGameButtonManager.h"
#include	"GameClearAnimation.h"

class GameClear:public IBaseEndGameProcess
{
	GameClearAnimation _clearAnimation;
	GameClearDollAnimation _dollAnim;

	EndGameButtonManager _endGameButtonManager;
	CTexture _nextStageTexture, _stageSelectTexture, _retryTexture;

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
