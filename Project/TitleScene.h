#pragma once
#include    "Mof.h"
#include	"IBaseScene.h"
#include	"BackGround.h"
#include	"BGM.h"
#include	"TitleLogoAnimation.h"
#include	"TitleClickAnimation.h"

class TitleScene :public IBaseScene
{
	BackGround _backGround;
	CTexture _titleBackTexture;
	CRectangle _titleBackRect;

	TitleLogoAnimation _titleLogoAnimation;
	TitleClickAnimation _titleClickAnimation;
	BGM _bgm;
	CSoundBuffer _music;
	bool _clearTutorial;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();

	void Render();
	void Release();
	void StopBGM() ;
};