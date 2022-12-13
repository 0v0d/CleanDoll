#pragma once
#include	"SceneManager.h"
#include	"IBaseScene.h"
#include	"BackGround.h"
#include	"BGM.h"
#include    "Mof.h"
#include "StageSelectScene.h"
#include "TutorialScene.h"
class TitleScene :public IBaseScene
{
	BackGround _backGround;
	CSpriteMotionController	_logo;
	CTexture _titleBackTexture;
	CTexture _startTexture;
	CTexture _titleLogoTexture;
	CTexture _titleLogoLoopTexture;
	CRectangle _titleBackRect;
	CRectangle _titleLogoRect;
	CRectangle  _titleLogoLoopRect;
	TutorialScene _tutorial;
	uint8_t _alpha;
	BGM _bgm;
	CSoundBuffer _music;
	bool _end;
	float _time;
	const float _increase = 0.003f;
	bool _clearTutorial;
	//titleLogo
	bool _loop;//Loop‚³‚ê‚½‚©‚Ì”»’è
	int _logoCount = 0;
	Vector2 _titleLogoPos = Vector2(-220, -500);
	const float _titleLogoScale=3.0f;
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
private:
	int CalcSequence(float x);
	void SetTitleLogoAnimationStatus();
	
};

