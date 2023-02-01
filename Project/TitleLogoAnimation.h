#pragma once
#include	"Mof.h"
#include	"ContactFile.h"
#include	"Trim.h"

class TitleLogoAnimation
{
	CTexture* _logoTextureArray = nullptr;
	const int _loopNumber = 2;
	CSpriteMotionController* _logoAnimation;
	CRectangle _renderRect;
	Vector2 _pos;
	
	ContactFile _contactFile;
	Trim _trim;

	int _animationValue;
	int _animationY, _animationCount;
	int _logoCount = 0;
	const float _scale = 1.5f;

public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();

	void Release();

private:
	void LoadTexture();
	void CreateAnimation();
	void CreateLogoAnimation(int number);
	void CalcuPosition(Vector2 rectSize);
	void SetNextAnimation();
};