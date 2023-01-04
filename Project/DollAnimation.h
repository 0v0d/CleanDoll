#pragma once
#include	"Mof.h"
class DollAnimation
{
	CSpriteMotionController	_motionController;
	CTexture* _dollTexture;
	const float _wait = 5;
	enum {
		WAIT_BROOM_1,
		WAIT_BROOM_2,
		WALK_BROOM,
		CLEAN_BROOM,
		WAIT_MOP_1,
		WAIT_MOP_2,
		WALK_MOP,
		CLEAN_MOP,
		PICK_MOP_1,
		PICK_MOP_2,
		//GET_CANDY
	};
	CRectangle _renderRect;
	int _currentMotion;
	const int _motionCount = 10;
	const int _motionValue = 20;
public:
	void Initialize();
	void ReLoad();
	void Update();

	void SetMoveBroomAnimationFlg(bool playMove);
	void SetMoveMopAnimationFlg(bool playMove);
	void StartCleanBroomAnimation() { _motionController.ChangeMotion(CLEAN_BROOM); }
	void StartCleanMopAnimation() { _motionController.ChangeMotion(CLEAN_MOP); }
	void StartSwitchToMopAnimation();
	void StartGetCandyAnimation();// {_motionController.ChangeMotion(GET_CANDY); }

	void WaitBroomAnimation();
	void WaitMopAnimation();
	int GetMotionValue() const { return _motionCount; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }
	float GetCleanTime() { return CUtilities::GetFPS()* _motionValue; }
private:
	void CreateAnimation();
	int WaitBroomAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
	int WaitMopAnimationLoop();

};