#pragma once
#include	"Mof.h"
class DollMopAnimation
{
	CSpriteMotionController	_motionController;
	const float _wait = 3;
	enum {
		WAIT_1,
		WAIT_2,
		WALK,
		CLEAN,
		GET_CANDY,
		PICK_MOP_1,
		PICK_MOP_2,
	};
	CRectangle _renderRect;
	int _currentMotion;
	const int _motionCount = 7;
	const int _motionValue = 20;
	float _moveSpeed;
public:
	void Initialize();
	void ReLoad();
	void Update();

	void SetMoveAnimationFlg(bool playMove);
	void StartCleanAnimation() { _motionController.ChangeMotion(CLEAN); }
	void StartGetCandyAnimation() { _motionController.ChangeMotion(GET_CANDY); }

	void StartSwitchToMopAnimation();
	void EndSwitchToMopAnimation();
	void WaitAnimation();
	int GetMotionValue() const { return _motionCount; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }
	float GetCleanTime() { return CUtilities::GetFPS() * _motionValue * _moveSpeed; }

	void SetMoveSpeed(float moveSpeed) { _moveSpeed = moveSpeed; }
private:
	void CreateAnimation();
	int WaitAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
};

