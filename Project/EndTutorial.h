#pragma once
#include "Mof.h"
#include "IBaseEndGameProcess.h"
#include "EndTutorialDollAnimation.h"
#include	"EndGameButtonManager.h"
#include "GameClearAnimation.h"

class EndTutorial :public IBaseEndGameProcess
{
	CTexture _stageSelectTexture;
	EndGameButtonManager _endGameButtonManager;
	GameClearAnimation _clearAnimation;
	EndTutorialDollAnimation _dollAnim;

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
