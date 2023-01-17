#pragma once
#include "Mof.h"
class GameClearBackGround
{
private:
	CSpriteMotionController _animation;
	CTexture _gameClearBackGroundTexture;
	Vector2 _pos;
	CRectangle _gameClearBackGroundRect;

	float _scale = 4.0f;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void CalcuPosition();
	void Render();
	void Release();
	bool IsEndMotion() { return _animation.IsEndMotion(); }
};



