#pragma once
#include "Mof.h"
class GameStartAnimation
{
	CSpriteMotionController	_motionController;
	CTexture _animationTexture;
	
	const float _wait = 3;
	const int _motionValue = 5;
	Vector2 _pos;
	CRectangle _renderRect;
	int _currentMotion;
	bool _end;

public:
	void Initialize();
	void StartCleanAnimation();

	void Update();
	void Render();
	void Release();
	
	bool IsEndAnimation() { return _end; }
private:
	void CalcuPosition(Vector2 rectSize);
	void CreateAnimation();
	void LoadTexture();
	void SetNextAnimation();
};

