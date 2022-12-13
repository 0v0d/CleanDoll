#pragma once
#include	"Mof.h"
#include	"IBaseEndGameProcess.h"
#include	"Button.h"
#include	"EndGameButtonAnimation.h"
class EndTutorial :public IBaseEndGameProcess
{
	EndGameButtonAnimation _endButtonAnimation;
	Button _stageSelectButton;
	CTexture _stageSelectTexture;
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