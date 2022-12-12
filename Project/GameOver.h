#pragma once
#include	"Mof.h"
#include	"IBaseEndGameProcess.h"
#include	"Button.h"
#include	"GameOverBackGround.h"
#include	"GameOverLogoAnimation.h"
#include	"EndGameButtonAnimation.h"

class GameOver:public IBaseEndGameProcess
{
private:
	GameOverBackGround _backGround;
	GameOverLogoAnimation _logoAnim;

	Vector2 _mousePos;

	const int _menuValue = 2;
	EndGameButtonAnimation* _endButtonAnimation = new EndGameButtonAnimation[_menuValue];
	Button _retryButton, _stageSelectButton;
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
	void UpdateAnimation();
};