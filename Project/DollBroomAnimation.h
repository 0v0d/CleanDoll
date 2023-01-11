#pragma once
#include	"Mof.h"
class DollBroomAnimation
{
	CSpriteMotionController	_motionController;
	const float _wait = 3;
	enum {
		WAIT_1,
		WAIT_2,
		WALK,
		CLEAN,
		GET_CANDY
	};
	CRectangle _renderRect;
	int _currentMotion;
	const int _motionCount = 5;
	const int _motionValue = 20;
public:
	void Initialize();
	void ReLoad();
	void Update();

	void SetMoveAnimationFlg(bool playMove);
	void StartCleanAnimation() { _motionController.ChangeMotion(CLEAN); }
	void StartGetCandyAnimation() {_motionController.ChangeMotion(GET_CANDY); }

	void WaitAnimation();
	int GetMotionValue() const { return _motionCount; }
	CRectangle GetRenderRect() { return _renderRect; }
	bool IsEndCurrentAnimation() { return _motionController.IsEndMotion(); }
	float GetCleanTime() { return CUtilities::GetFPS() * _motionValue; }
private:
	void CreateAnimation();
	int WaitAnimationLoop() { return _currentMotion = (_currentMotion + 1) % 2; }
};

