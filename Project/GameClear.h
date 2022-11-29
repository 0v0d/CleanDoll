#pragma once
#include	"IBaseEndGameProcess.h"
#include	"Button.h"

class GameClear:public IBaseEndGameProcess
{
	Vector2 _mousePos;

	Vector2 _firstButtonPos,_secondButtonPos,_thirdButtonPos;
	Button _nextStageButton, _stageSelectButton, _retryButton;
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
};