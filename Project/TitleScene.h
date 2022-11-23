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
	float _time;
	const float _increase = 0.003;

	//titleLogo
	bool _loop;//Loop‚³‚ê‚½‚©‚Ì”»’è
	int _logoCount = 0;
	Vector2 _titleLogoPos = Vector2(-220, -500);
	const float _titleLogoScale=3.0f;
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

