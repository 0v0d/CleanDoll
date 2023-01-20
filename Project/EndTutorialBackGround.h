#pragma once
#include "Mof.h"
class EndTutorialBackGround
{
private:
	CSpriteMotionController _animation;
	CTexture _endTutorialGameClearTexture;
	Vector2 _pos;
	CRectangle _endTutorialGameClearRect;

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



