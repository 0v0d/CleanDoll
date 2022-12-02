#pragma once
#include	"Mof.h"
class DollAnimation
{
	CSpriteMotionController	_motionController;
	CTexture* _dollTexture;
	const int _wait = 3;
	enum {
		WAIT_1,
		WAIT_2,
		WALK,
		CLEAN,
		MOTION_COUNT
	};
	CRectangle _renderRect;
	int _currentMotion;

public:
	void Initialize();
	void ReLoad();
	void SetTexture(CTexture* texture) { _dollTexture = texture; }
	void Update();
	void SetMoveAnimationFlg(bool playMove);
	void StartCleanAnimation() { _motionController.ChangeMotion(CLEAN); }

	int GetMotionValue() const { return MOTION_COUNT; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }

private:
	void CreateAnimation();
	int WaitAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
	void UpdateAnimation();
};

