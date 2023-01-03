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
		WALK_BROOM,
		CLEAN_BROOM,
		WALK_MOP,
		CLEAN_MOP,
		PICK_MOP_1,
		PICK_MOP_2,
	};
	CRectangle _renderRect;
	int _currentMotion;
	const int _motionCount = 8;
	const int _motionValue = 20;
public:
	void Initialize();
	void ReLoad();
	void CreateAnimation();
	void Update();
	void SetMoveBroomAnimationFlg(bool playMove);
	void SetMoveMopAnimationFlg(bool playMove);
	void StartCleanBroomAnimation() { _motionController.ChangeMotion(CLEAN_BROOM); }
	void StartCleanMopAnimation() { _motionController.ChangeMotion(CLEAN_MOP); }
	void StartSwitchToMopAnimation();
	int GetMotionValue() const { return _motionCount; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }
	float GetCleanTime() { return CUtilities::GetFPS()* _motionValue; }
private:

	int WaitAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
	void UpdateAnimation();
};