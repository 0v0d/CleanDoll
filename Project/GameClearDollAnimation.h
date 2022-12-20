#pragma once
#include "Mof.h"
class GameClearDollAnimation
{
private:
	CSpriteMotionController _animation;
	CTexture _clearDollTexture;
	Vector2 _pos;
	CRectangle _clearDollRect;

	float _scale = 2.0f;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
};

