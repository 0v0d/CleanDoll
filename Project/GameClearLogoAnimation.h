#pragma once
#include "Mof.h"
class GameClearLogoAnimation
{
private:
	CSpriteMotionController _animation;
	CTexture _stageClearTexture;
	Vector2 Pos;
	CRectangle _clearLogRect;

	float _scale=4.0f;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	bool IsEndeMotion();

};

