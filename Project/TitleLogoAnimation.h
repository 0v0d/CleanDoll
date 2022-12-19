#pragma once
#include	"Mof.h"

class TitleLogoAnimation
{
	CTexture _logoTexture,_loopLogoTexture;
	CTexture* _currentAnimationTexture;
	CSpriteMotionController	_logoAnimation,_loopLogoAnimation;
	CSpriteMotionController* _currentAniamtion;
	CRectangle _renderRect;
	Vector2 _pos;

	const int _logoAnimationValue = 9;
	const int _loopLogoAnimationValue = 5;
	int _logoCount = 0;
	bool _loopAnimation;
	const float _scale = 3.0f;

public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();

private:
	void LoadTexture();
	void CreateAnimation();
	void CalcuPosition(Vector2 rectSize);
	void SetNextAnimation();
};