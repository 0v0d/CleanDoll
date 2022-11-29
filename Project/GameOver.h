#pragma once
#include	"IBaseEndGameProcess.h"
#include	"Button.h"

class GameOver:public IBaseEndGameProcess
{
private:
	Vector2 _mousePos;

	Button _retryButton, _stageSelectButton;
	Vector2 _firstButtonPos, _secondButtonPos;
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