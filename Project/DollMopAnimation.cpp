#include "DollMopAnimation.h"

void DollMopAnimation::Initialize() {
	CreateAnimation();
}

void DollMopAnimation::CreateAnimation() {
	SpriteAnimationCreate _dollAnimation[] = {
{

	"Wait_Mop",
	0,1280,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0}}
},
{
	"Wait_Mop",
	0,1600,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0}}
},
{
	"Walk_Mop",
	0,1920,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0} ,{_wait,10,0},{_wait,11,0},{_wait,12,0},{_wait,13,0},{_wait,14,0},{_wait,15,0},{_wait,16,0},
	{_wait,17,0},{_wait,18,0},{_wait,19,0}}
},
{
	"Clean_Mop",
	0,2240,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0}}
},
	{
	"Pick_Mop",
	0,2560,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0}}
	},
	{
	"Pick_Mop",
	0,2880,
	320,320,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0}}
	},
	};
	_motionController.Create(_dollAnimation, _motionCount);
}

void DollMopAnimation::ReLoad() {
	_currentMotion = 0;
	_motionController.ChangeMotion(WaitMopAnimationLoop());
}

void DollMopAnimation::Update() {
	_motionController.AddTimer(CUtilities::GetFrameSecond());
	_renderRect = _motionController.GetSrcRect();

	if ((_motionController.GetMotionNo() == PICK_MOP_1) && _motionController.IsEndMotion())
		_motionController.ChangeMotion(PICK_MOP_2);
}

void DollMopAnimation::WaitMopAnimation() {
	if ((_motionController.GetMotionNo() == WAIT_MOP_1 || _motionController.GetMotionNo() == WAIT_MOP_2) && _motionController.IsEndMotion()) {
		_motionController.ChangeMotion(WaitMopAnimationLoop());
	}
}

void DollMopAnimation::SetMoveMopAnimationFlg(bool playMove) {
	if (!playMove) {
		_motionController.ChangeMotion(WaitMopAnimationLoop());
	}
	else if (_motionController.GetMotionNo() != WALK_MOP) {
		_motionController.ChangeMotion(WALK_MOP);
	}
}

void  DollMopAnimation::StartSwitchToMopAnimation() {
	_motionController.ChangeMotion(PICK_MOP_1);
}