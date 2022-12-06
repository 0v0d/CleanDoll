#pragma once
#include	"IBaseEndGameProcess.h"
#include	"Button.h"
#include	"GameClearLogoAnimation.h"
#include	"GameClearBackGround.h"

class GameClear:public IBaseEndGameProcess
{
	GameClearLogoAnimation _gameClearAnim;
	GameClearBackGround _clearBackGround;

	Vector2  _nextButtonPos, _stageSelectButtonPos, _retryButtonPos;
	CTexture _nextStageTexture, _stageSelectTexture, _retryTexture;
	Button _nextStageButton, _stageSelectButton, _retryButton;
	Vector2 _backStageClearPos;
	CTexture _backStageClearTexture;
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
	void UpdateAnimation();
};