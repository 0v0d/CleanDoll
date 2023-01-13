#pragma once
class SlideInUI
{
private:
	float* _pos = nullptr;
	float _positionX;
	float slideInPos;
	bool _left;
public:
	void Update();
	void SetPosition(float positionX,float* pos,bool left);
};