#include "DollBroomAnimation.h"
void DollBroomAnimation::Initialize() {
	CreateAnimation();
}

void DollBroomAnimation::CreateAnimation() {
	SpriteAnimationCreate _dollAnimation[] = {
	{
	"Wait_Broom",
	0,0,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0},}
	},
	{
	"Wait_Broom",
	0,320,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0},}
	},
	{
	"Walk_Broom",
	0,640,
	320,320,
	true,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0}}
	},
	{
	"Clean_Broom",
	0,960,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0}}
	},
	{
	"GET_CANDY",
	0,1280,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0}}
	},
};
	_motionController.Create(_dollAnimation, _motionCount);
}

void DollBroomAnimation::ReLoad() {
	_currentMotion = 0;
	_motionController.ChangeMotion(WaitAnimationLoop());
}

void DollBroomAnimation::Update() {
	_motionController.AddTimer(CUtilities::GetFrameSecond()*_moveSpeed);
	_renderRect = _motionController.GetSrcRect();
}

void DollBroomAnimation::WaitAnimation() {
	if ((_motionController.GetMotionNo() == WAIT_1 || _motionController.GetMotionNo() == WAIT_2) && _motionController.IsEndMotion()) {
		_motionController.ChangeMotion(WaitAnimationLoop());
	}
}

void DollBroomAnimation::SetMoveAnimationFlg(bool playMove) {
	if (!playMove) {
		_motionController.ChangeMotion(WaitAnimationLoop());
	}
	else if (_motionController.GetMotionNo() != WALK) {
		_motionController.ChangeMotion(WALK);
	}
}