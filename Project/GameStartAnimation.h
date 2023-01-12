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

	enum {
		STARTANIM_1,
		STARTANIM_2,
		STARTANIM_3,
		STARTANIM_4,
		STARTANIM_5,
	};

public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();

	void StartCleanAnimation() { _motionController.ChangeMotion(STARTANIM_1); }
	
	bool IsEndAnimation() { return _motionController.IsEndMotion(); }
private:
	void CalcuPosition(Vector2 rectSize);
	void CreateAnimation();
	void LoadTexture();
	void SetNextAnimation();
};

