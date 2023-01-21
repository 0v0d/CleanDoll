#pragma once
#include	"Mof.h"
class GameClearAnimation
{
	CSpriteMotionController _animation;
	CTexture _gameOverTexture;
	Vector2 _pos;
	CRectangle _renderRect;
	const int _animationValue = 5;
	const int _animationMaxCount = 4;
	int _animationCount;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
	bool IsEndMotion() { return _animation.IsEndMotion(); }
private:
	void LoadTexture();
	void CreateAnimation();
	void SetNextAnimation();
};