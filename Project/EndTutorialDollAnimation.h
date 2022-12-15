#pragma once
#include "Mof.h"
class EndTutorialDollAnimation
{
private:
	CSpriteMotionController _animation;
	CTexture _clearDollTexture;
	Vector2 _pos;
	CRectangle _clearDollRect;

	const float _scale = 2.0f;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
	bool IsEndeMotion() { return _animation.IsEndMotion(); }
private:
	void LoadTexture();
};

