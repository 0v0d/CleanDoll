#include "DollAnimation.h"

void DollAnimation::Initialize() {
	CreateAnimation();
}

void DollAnimation::CreateAnimation() {
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

void DollAnimation::ReLoad() {
	_currentMotion = 0;
	_motionController.ChangeMotion(WaitBroomAnimationLoop());
}

void DollAnimation::Update()
{
	_motionController.AddTimer(CUtilities::GetFrameSecond());
	_renderRect = _motionController.GetSrcRect();
}

void DollAnimation::WaitBroomAnimation()
{
	if ((_motionController.GetMotionNo() == WAIT_BROOM_1 || _motionController.GetMotionNo() == WAIT_BROOM_2) && _motionController.IsEndMotion()) {
		_motionController.ChangeMotion(WaitBroomAnimationLoop());
	}
}

void DollAnimation::WaitMopAnimation()
{
	/*if ((_motionController.GetMotionNo() == WAIT_MOP_1 || _motionController.GetMotionNo() == WAIT_MOP_2) && _motionController.IsEndMotion()) {
		_motionController.ChangeMotion(WaitMopAnimationLoop());
	}*/
}

int DollAnimation::WaitMopAnimationLoop()
{
	if(_currentMotion % 5 <= 0){
		_currentMotion = WAIT_MOP_1;
	}
	else{
		_currentMotion = WAIT_MOP_1;
	}
	return _currentMotion;
		
}

void DollAnimation::StartSwitchToMopAnimation() {
	_motionController.ChangeMotion(PICK_MOP_1);
	if(_motionController.GetMotionNo() == PICK_MOP_1 && _motionController.IsEndMotion()){
		_motionController.ChangeMotion(PICK_MOP_2);
	}
}

void DollAnimation::SetMoveBroomAnimationFlg(bool playMove) {
	if (!playMove) {
		_motionController.ChangeMotion(WaitBroomAnimationLoop());
	}
	else if (_motionController.GetMotionNo() != WALK_BROOM) {
		_motionController.ChangeMotion(WALK_BROOM);
	}
}

void DollAnimation::SetMoveMopAnimationFlg(bool playMove) {
	/*if (!playMove) {
		_motionController.ChangeMotion(WaitMopAnimationLoop());
	}
	else if (_motionController.GetMotionNo() != WALK_MOP) {
		_motionController.ChangeMotion(WALK_MOP);
	}*/
}


