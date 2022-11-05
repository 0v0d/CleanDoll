#pragma once
#include "Mof.h"
class SliderButton
{
private:
	//�T�C�Y�֌W
	Vector2 _buttonSize;
	Vector2 _barSize;
	Vector2 _buttonHalfSize;
	Vector2 _barHalfSize;
	//���W�֌W
	Vector2 _buttonPos;
	Vector2 _barPos;
	//�����蔻��֌W
	CRectangle	_buttonRect;
	CRectangle	_barRect;

	float		 _value;
	const float  _half = 0.5;
	const int   _maxValue = 100;
	bool		_onClick;


public:
	void SetButtonStatu(Vector2 buttonSize, Vector2 buttonPos, Vector2 barSize, float value);
	void ButtonHorizonStatu();
	void ButtonVerticalStatu();
	void Update();
	void HorizonValue();
	void VerticalValue();
	void MoveHorizonButton(Vector2 mousePos);
	void MoveVerticalButton(Vector2 mousePos);
	void Render();
	bool IsCollisionButton(Vector2 mousePos) { return _buttonRect.CollisionPoint(mousePos); }
	float GetValue() { return _value; }
};

