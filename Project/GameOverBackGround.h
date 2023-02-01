#pragma once
#include "Mof.h"
class GameOverBackGround
{
	private:
		CSpriteMotionController _animation;
		CTexture _gameOverBackGroundTexture;
		Vector2 _pos;
		CRectangle _gameOverBackGroundRect;

		float _scale = 4.0f;
public:
	void Initialize();
	void LoadTexture();
	void ReLoad();
	void Update();
	void CalcuPosition();
	void Render();
	void Release();
	bool IsEndMotion() { return _animation.IsEndMotion(); }
};



