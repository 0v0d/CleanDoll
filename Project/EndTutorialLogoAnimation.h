#pragma once
#include "Mof.h"
class EndTutorialLogoAnimation
{
private:
	CSpriteMotionController _animation;
	CTexture _clearTexture;
	Vector2 _pos;
	CRectangle _clearLogRect;

	const float _scale = 4.0f;
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

