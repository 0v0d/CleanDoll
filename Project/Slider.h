#pragma once
#include	"Mof.h"
#include	"SliderBar.h"
#include	"SliderButton.h"

enum  DIRECTION_TYPE
{
	HORIZON,
	VERTICAL,
};

class Slider
{
	SliderButton _button;
	SliderBar    _bar;
	DIRECTION_TYPE _direction;
	Vector2 _mousePos;
	bool _onClick;
public:
	void SetStatu(Vector2 barPos, Vector2 barSize,  Vector2 buttonSize, float value, DIRECTION_TYPE direction);
	float GetValue() { return _button.GetValue(); }
	void PushSlider();
	void PullSlider();
	void Update();
	void Render();
private:
	void SetClickFlg(bool flg) { _onClick = flg; }
	bool IsClick() { return _onClick; }
};