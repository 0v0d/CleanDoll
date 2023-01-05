#pragma once
#include	"Mof.h"
class DollMopAnimation
{
	CSpriteMotionController	_motionController;
	const float _wait = 5;
	enum {
		WAIT_MOP_1,
		WAIT_MOP_2,
		WALK_MOP,
		CLEAN_MOP,
		PICK_MOP_1,
		PICK_MOP_2,
	};
	CRectangle _renderRect;
	int _currentMotion;
	const int _motionCount = 6;
	const int _motionValue = 20;
public:
	void Initialize();
	void ReLoad();
	void Update();

	void SetMoveMopAnimationFlg(bool playMove);
	void StartCleanMopAnimation() { _motionController.ChangeMotion(CLEAN_MOP); }
	
	void StartSwitchToMopAnimation();
	void EndSwitchToMopAnimation();
	void WaitMopAnimation();
	int GetMotionValue() const { return _motionCount; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }
	float GetCleanTime() { return CUtilities::GetFPS() * _motionValue; }
private:
	void CreateAnimation();
	int WaitMopAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
};

