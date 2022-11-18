#pragma once
#include	"SceneManager.h"
#include	"IBaseScene.h"
#include	"BackGround.h"
#include    "Mof.h"
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
	uint8_t _alpha;
	bool _end;
	bool _loop;
	float _time;
	const float _increase = 0.003;

	int _logoCount = 0;
	int _logoLoopCount = 0;
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
	void SetTitleLogoLoopAnimationStatus();
};

