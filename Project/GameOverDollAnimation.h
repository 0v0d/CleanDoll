#pragma once
#include "Mof.h"
class GameOverDollAnimation
{
private:
	CSpriteMotionController _animation;
	CTexture _dollTexture;
	Vector2 _pos;
	CRectangle _dollRect;

	float _scale = 2.0f;
public:
	void Initialize();
	void LoadTexture();
	void ReLoad();
	void Update();
	void Render();
	void Release();
	bool IsEndeMotion() { return _animation.IsEndMotion(); }
};

