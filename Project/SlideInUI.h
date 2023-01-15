#pragma once
#include	"Mof.h"
class SlideInUI
{
private:
	float* _posX = nullptr;
	
	float _speed;
	const int _time = 45;
	int _count;
	int _initPosX;

	bool _end;

public:
	void Start();
	void SetStatu(float targetPos, float* posX, bool left);
	void Update();
};