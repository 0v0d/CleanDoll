#pragma once
#include	"Mof.h"
class DollBroomAnimation
{
	CSpriteMotionController	_motionController;
	const float _wait = 3;
	enum {
		WAIT_BROOM_1,
		WAIT_BROOM_2,
		WALK_BROOM,
		CLEAN_BROOM,
		//GET_CANDY
	};
	CRectangle _renderRect;
	int _currentMotion;
	const int _motionCount = 4;
	const int _motionValue = 20;
public:
	void Initialize();
	void ReLoad();
	void Update();

	void SetMoveBroomAnimationFlg(bool playMove);
	void StartCleanBroomAnimation() { _motionController.ChangeMotion(CLEAN_BROOM); }

	void StartGetCandyAnimation();// {_motionController.ChangeMotion(GET_CANDY); }

	void WaitBroomAnimation();
	int GetMotionValue() const { return _motionCount; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }
	float GetCleanTime() { return CUtilities::GetFPS() * _motionValue; }
private:
	void CreateAnimation();
	int WaitBroomAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
};

