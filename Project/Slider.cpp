#include "Slider.h"

void Slider::SetStatu(Vector2 barPos,Vector2 barSize, Vector2 buttonSize, float value, DIRECTION_TYPE direction)
{
	_direction = direction;
	_bar.SetBarStatu(barSize, barPos);
	_button.SetButtonStatu(barSize, barPos, buttonSize, value);

	if (_direction == HORIZON) 
	{
		_button.ButtonHorizonStatu();
	}
	else if (_direction == VERTICAL)
	{
		_button.ButtonVerticalStatu();
	}
}

void Slider::Update()
{
	_button.Update();
	if (_direction == HORIZON) 
	{
		_button.HorizonValue();
	}
	else if (_direction == VERTICAL) 
	{
		_button.VerticalValue();
	}

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

	if (IsClick())
	{
		if (_direction == HORIZON)	_button.MoveHorizonButton(_mousePos);
		else if (_direction == VERTICAL)  _button.MoveVerticalButton(_mousePos);
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