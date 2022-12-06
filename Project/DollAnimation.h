#pragma once
#include	"Mof.h"
class DollAnimation
{
	CSpriteMotionController	_motionController;
	CTexture* _dollTexture;
	const float _wait = 3;
	enum {
		WAIT_1,
		WAIT_2,
		WALK,
		CLEAN,
	};
	CRectangle _renderRect;
	int _currentMotion;
	const int _motionCount = 4;
	const int _motionValue = 20;
public:
	void Initialize();
	void ReLoad();
	void CreateAnimation();
	void Update();
	void SetMoveAnimationFlg(bool playMove);
	void StartCleanAnimation() { _motionController.ChangeMotion(CLEAN); }

	int GetMotionValue() const { return _motionCount; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }
	float GetCleanTime() { return CUtilities::GetFPS()* _motionValue; }
private:

	int WaitAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
	void UpdateAnimation();
};

