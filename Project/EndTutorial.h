#pragma once
#include "Mof.h"
#include "IBaseEndGameProcess.h"
#include "Button.h"
#include "EndGameButtonAnimation.h"
#include "EndTutorialBackGround.h"
#include "EndTutorialDollAnimation.h"
#include "EndTutorialLogoAnimation.h"
#include "SceneManager.h"


class EndTutorial :public IBaseEndGameProcess
{
	EndGameButtonAnimation _endGameButton;
	Button _stageSelectButton;
	CTexture _stageSelectTexture;
	EndTutorialLogoAnimation _logoAnimation;
	EndTutorialDollAnimation _dollAnimation;
	EndTutorialBackGround _backGround;
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