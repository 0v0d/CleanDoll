#pragma once
#include	"SceneManager.h"
#include	"IBaseScene.h"
#include	"BackGround.h"
#include    "Mof.h"
class TitleScene :public IBaseScene
{
	BackGround _backGround;
	CSpriteMotionController	_controller;
	CTexture _titleBackTexture;
	CTexture _startTexture;
	CTexture _titleLogoTexture;
	CRectangle _titleBackRect;
	CRectangle _titleLogoRect;
	uint8_t _alpha;
	bool _end;
	float _time;
	const float _increase = 0.003;

	int _logoCount = 1;
	DWORD _nowTime;
	DWORD _beginTime;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void InputMouseKey();
	void Render();
	void Release();
private:
	int CalcSequence(float x);
	void SetTitleLogoAnimationStatus();
};