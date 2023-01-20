#pragma once
#include "Mof.h"
class GameClearLogoAnimation
{
private:
	CSpriteMotionController _animation;
	CTexture _stageClearTexture;
	Vector2 _pos;
	CRectangle _clearLogRect;

	float _scale = 4.0f;
public:
	void Initialize();
	void LoadTexture();
	void ReLoad();
	void Update();
	void Render();
	void Release();
	bool IsEndeMotion() { return _animation.IsEndMotion();}

};

