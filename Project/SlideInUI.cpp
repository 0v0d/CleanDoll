#include "SlideInUI.h"

void SlideInUI::SetStatu(float targetPos, float* posX, bool left)
{
	_posX = posX;
	int moveVal = 300;
	int dir = left ? 1 : -1;
	_initPosX = targetPos - moveVal * dir;
	_speed = (float)moveVal / _time * dir;
}

void SlideInUI::Start() {
	_end = false;
	_count = 0;

	*_posX = _initPosX;
}

void SlideInUI::Update()
{
	if (_end) return;

	*_posX += _speed;

	_count++;
	if (_count >= _time) _end = true;
}