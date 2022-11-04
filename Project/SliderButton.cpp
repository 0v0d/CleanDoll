#include "SliderButton.h"
void SliderButton::SetButtonStatu(Vector2 barSize, Vector2 barPos, Vector2 buttonSize, float value)
{
	_barSize = barSize;
	_barPos = barPos;
	_value = value;
	_buttonSize = buttonSize;
	_buttonHalfSize = _buttonSize * _half;
	_barHalfSize = _barSize * _half;
}
void SliderButton::ButtonHorizonStatu()
{
	_buttonPos.x = _barPos.x + _barSize.x * _value - _buttonSize.x * _value;
	_buttonPos.y = _barPos.y + _barHalfSize.y - _buttonHalfSize.y;
	_barRect = CRectangle(_barPos.x, _barPos.y, _barPos.x + _barSize.x, _barPos.y + _barSize.y);
	_buttonRect = CRectangle(_buttonPos.x, _buttonPos.y, _buttonPos.x + _buttonSize.x, _buttonPos.y + _buttonSize.y);
}
void SliderButton::ButtonVerticalStatu()
{
	_buttonPos.x = _barPos.x + _barHalfSize.x - _buttonHalfSize.x;
	_buttonPos.y = _barPos.y;
	_barRect = CRectangle(_barPos.x, _barPos.y, _barPos.x + _barSize.x, _barPos.y + _barSize.y);
	_buttonRect = CRectangle(_buttonPos.x, _buttonPos.y, _buttonPos.x + _buttonSize.x, _buttonPos.y + _buttonSize.y);
}

void SliderButton::Update()
{
	_buttonRect = CRectangle(_buttonPos.x, _buttonPos.y,
		_buttonPos.x + _buttonSize.x, _buttonPos.y + _buttonSize.y);
}
void SliderButton::HorizonValue()
{
	_value = (_buttonPos.x - _barRect.Left) / ((_barSize.x - _buttonSize.x) / _maxValue);
}

void SliderButton::VerticalValue()
{
	_value = (_buttonPos.y - _barRect.Top) / ((_barSize.y - _buttonSize.y) / _maxValue);
}

void SliderButton::MoveHorizonButton(Vector2 mousePos)
{
	_buttonPos.x = _barRect.Left > mousePos.x - _buttonHalfSize.x ?
		_barRect.Left : min(_barRect.Right - _buttonSize.x, mousePos.x - _buttonHalfSize.x);
}

void SliderButton::MoveVerticalButton(Vector2 mousePos)
{
	_buttonPos.y = _barRect.Top > mousePos.y - _buttonHalfSize.y ?
		_barRect.Top : min(_barRect.Bottom - _buttonSize.y, mousePos.y - _buttonHalfSize.y);
}

void SliderButton::Render()
{
	CGraphicsUtilities::RenderRect(_buttonRect, MOF_COLOR_RED);
}
