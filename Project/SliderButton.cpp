#include "SliderButton.h"

void SliderButton::SetButtonStatu(Vector2 barSize, Vector2 barPos, CTexture* buttonTexture, float value)
{
	_barSize = barSize;
	_barPos.x = barPos.x;
	_barPos.y = barPos.y - _barSize.y / 2;
	_value = value;
	_buttonTexture = buttonTexture;
	_buttonSize = Vector2(buttonTexture->GetWidth(), buttonTexture->GetHeight());
}

void SliderButton::CalcuButtonHorizonStatu()
{
	_buttonPos.x = _barPos.x + _barSize.x / 2 * _value - _buttonSize.x * _value;
	_buttonPos.y = _barPos.y + _barSize.y / 2 - _buttonSize.y / 2;
	_barRect = CRectangle(_barPos.x - _barSize.x/2, _barPos.y - _barSize.y / 2, _barPos.x + _barSize.x/2, _barPos.y + _barSize.y);
	_buttonRect = CRectangle(_buttonPos.x, _buttonPos.y, _buttonPos.x + _buttonSize.x, _buttonPos.y + _buttonSize.y);
}

void SliderButton::CalcuButtonVerticalStatu()
{
	_buttonPos.x = _barPos.x - _buttonSize.x / 2;
	_buttonPos.y = _barPos.y;
	_barRect = CRectangle(_barPos.x, _barPos.y, _barPos.x + _barSize.x, _barPos.y + _barSize.y);
	_buttonRect = CRectangle(_buttonPos.x, _buttonPos.y, _buttonPos.x + _buttonSize.x, _buttonPos.y + _buttonSize.y);
}

void SliderButton::Update()
{
	_buttonRect = CRectangle(_buttonPos.x, _buttonPos.y,
		_buttonPos.x + _buttonSize.x, _buttonPos.y + _buttonSize.y);
}
void SliderButton::CalcuHorizonValue()
{
	_value = (_buttonPos.x - _barRect.Left) / ((_barSize.x - _buttonSize.x) / _maxValue);
}
void SliderButton::CalcuVerticalValue()
{
	_value = (_buttonPos.y - _barRect.Top) / ((_barSize.y - _buttonSize.y) / _maxValue);
}

void SliderButton::MoveHorizonButton(Vector2 mousePos)
{
	_buttonPos.x = _barRect.Left > mousePos.x - _buttonSize.x / 2 ?
		_barRect.Left : min(_barRect.Right - _buttonSize.x, mousePos.x - _buttonSize.x / 2);
}

void SliderButton::MoveVerticalButton(Vector2 mousePos)
{
	_buttonPos.y = _barRect.Top > mousePos.y - _buttonSize.y / 2 ?
		_barRect.Top : min(_barRect.Bottom - _buttonSize.y, mousePos.y - _buttonSize.y / 2);
}
void SliderButton::Render()
{
	_buttonTexture->Render(_buttonRect);
	//CGraphicsUtilities::RenderRect(_buttonRect, MOF_COLOR_RED);
}

void SliderButton::MouseWheelMove(float movewheel)
{
	if (movewheel > 0 && _buttonPos.y - _wheelSensitivity < _barPos.y)
		_buttonPos.y = _barPos.y + _wheelSensitivity;
	if (movewheel < 0 && _buttonPos.y + _buttonSize.y + _wheelSensitivity > _barPos.y + _barSize.y)
		_buttonPos.y = _barPos.y + _barSize.y - _buttonSize.y - _wheelSensitivity;
	if (movewheel > 0)
		_buttonPos.y -= _wheelSensitivity;
	if (movewheel < 0)
		_buttonPos.y += _wheelSensitivity;
}
