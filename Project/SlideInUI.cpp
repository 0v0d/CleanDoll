#include "SlideInUI.h"

void SlideInUI::SetPosition(float positionX,float* pos,bool left)
{
	_left = left;
	_positionX = positionX;
	const int slideInPos = 300;
	_pos = pos;
	if (_left) {
		*_pos = _positionX - slideInPos;
	}
	else{
		*_pos = _positionX + slideInPos;
	}
	
}

void SlideInUI::Update()
{
	const int speed = 3;

	if(_left){
		if (*_pos <_positionX) *_pos += speed;
	}
	else{
		if (*_pos > _positionX) *_pos -= speed;
	}
}