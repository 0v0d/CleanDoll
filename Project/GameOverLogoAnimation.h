#pragma once
#include "Mof.h"
class GameOverLogoAnimation
{
private:
	CSpriteMotionController _animation;
	CTexture _missTakeLogTexture;
	Vector2 _pos;
	CRectangle _missTakeLogRect;

	float _scale = 4.0f;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
	bool IsEndMotion() { return _animation.IsEndMotion();}

};

