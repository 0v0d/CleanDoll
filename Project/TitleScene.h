#pragma once
#include    "Mof.h"
#include	"IBaseScene.h"
#include	"BackGround.h"
#include	"BGM.h"
#include	"TitleLogoAnimation.h"
#include	"TitleClickAnimation.h"
#include	"FadeIn.h"
#include	"TitleSceneTransition.h"

class TitleScene :public IBaseScene
{
	BackGround _backGround;
	CTexture _titleBackTexture;
	CRectangle _titleBackRect;

	TitleLogoAnimation _titleLogoAnimation;
	TitleClickAnimation _titleClickAnimation;
	CSoundBuffer _music;

	FadeIn _fadeIn;

	bool _openTransition;
	TitleSceneTransition _transition;
	CSoundBuffer		_ClickSound;
public:
	void Initialize();
	void LoadTexture();
	void LoadSound();
	void ReLoad();
	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();

	void Render();
	void Release();

	CSoundBuffer* GetBGM() { return &_music; }
};