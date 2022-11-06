#include "Slider.h"

void Slider::SetStatu(Vector2 barPos,Vector2 barSize, Vector2 buttonSize, float value, DIRECTION_TYPE direction)
{
	_direction = direction;
	_bar.SetBarStatu(barSize, barPos);
	_button.SetButtonStatu(barSize, barPos, buttonSize, value);

	if (_direction == HORIZON)	_button.CalcuButtonHorizonStatu();
	else if (_direction == VERTICAL)  _button.CalcuButtonVerticalStatu();
	_onClick = false;
}

void Slider::Update()
{
	_button.Update();
	if (_direction == HORIZON)	_button.CalcuHorizonValue();
	else if (_direction == VERTICAL)  _button.CalcuVerticalValue();

	if (IsClick())
	{
		g_pInput->GetMousePos(_mousePos);
		if (_direction == HORIZON)	_button.MoveHorizonButton(_mousePos);
		else if (_direction == VERTICAL)  _button.MoveVerticalButton(_mousePos);
	}
}

void Slider::PushSlider()
{
	g_pInput->GetMousePos(_mousePos);
	if (_bar.IsCollisionBar(_mousePos) || _button.IsCollisionButton(_mousePos))
	{
		SetClickFlg(true);
	}
}

void Slider::PullSlider()
{
	SetClickFlg(false);
}

void Slider::Render()
{
	_bar.Render();
	_button.Render();
}