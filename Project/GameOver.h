#pragma once
#include	"IBaseEndGameProcess.h"
#include	"Button.h"
#include	"GameOverBackGround.h"
#include	"GameOverLogoAnimation.h"

class GameOver:public IBaseEndGameProcess
{
private:
	GameOverBackGround _backGround;
	GameOverLogoAnimation _logoAnim;

	Vector2 _mousePos;

	const int _menuValue = 2;
	Button* _button=new Button[_menuValue];
	Vector2 _retryPos, _stageSelectPos;
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
};