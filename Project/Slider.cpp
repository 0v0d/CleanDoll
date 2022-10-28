#include "Slider.h"


void Slider::SetBarStatu(Vector2 barSize, Vector2 buttonSize, Vector2 barPos, DRECTION_TYPE drectionType)
{
	_drectionType = drectionType;
	_barSize = barSize;
	_buttonSize = buttonSize;
	_barPos = barPos;
	_barRect = CRectangle(_barPos.x, _barPos.y, _barPos.x + _barSize.x, _barPos.y + _barSize.y);
	_halfButtonSize = _buttonSize * _half;
	_halfBarSize = _barSize * _half;
	switch (_drectionType)
	{
	case DRECTION_TYPE::HORIZON:
		_buttonPos.x = _barPos.x + _barSize.x * _iniPos - _buttonSize.x * _iniPos;
		_buttonPos.y = _barPos.y + _halfBarSize.y - _halfButtonSize.y;
		break;
	case DRECTION_TYPE::VERTICAL:
		_buttonPos.x = _barPos.x + _halfBarSize.x - _halfButtonSize.x;
		_buttonPos.y = _barPos.y;
		break;
	}
}

void Slider::Update()
{
	_buttonRect = CRectangle(_buttonPos.x, _buttonPos.y,
		_buttonPos.x + _buttonSize.x, _buttonPos.y + _buttonSize.y);
	switch (_drectionType)
	{
	case DRECTION_TYPE::HORIZON:
		_moveValue = (_buttonPos.x - _barPos.x) / ((_barSize.x - _buttonSize.x) / _maxValue);
		break;
	case DRECTION_TYPE::VERTICAL:
		_moveValue = (_buttonPos.y - _barPos.y) / ((_barSize.y - _buttonSize.y) / _maxValue);
		break;
	}

}

void Slider::PushSlider(Vector2 mousePos)
{
	if (CheckClickBar(mousePos) || CheckClickButton(mousePos))
	{
		SetClick(true);
	}
}

void Slider::PullSlider()
{
	SetClick(false);
}

void Slider::ClickSlider(Vector2 mousePos)
{
	if (IsClick())
	{
		Move(mousePos);
	}
}

void Slider::Move(Vector2 mousePos)
{
	switch (_drectionType)
	{
	case DRECTION_TYPE::HORIZON:
		_buttonPos.x = _barRect.Left > mousePos.x - _halfButtonSize.x ?
			_barRect.Left : min(_barRect.Right - _buttonSize.x, mousePos.x - _halfButtonSize.x);
		break;
	case DRECTION_TYPE::VERTICAL:
		_buttonPos.y = _barRect.Top > mousePos.y - _halfButtonSize.y ?
			_barRect.Top : min(_barRect.Bottom - _buttonSize.y, mousePos.y - _halfButtonSize.y);
		break;
	}
}

void Slider::Render()
{
	CGraphicsUtilities::RenderRect(_barRect, MOF_COLOR_GREEN);
	CGraphicsUtilities::RenderRect(_buttonRect, MOF_COLOR_RED);
	CGraphicsUtilities::RenderString(0, 0, "%f", _moveValue);
}

void Slider::MouseWheelMove(float  moveWheel)
{
	if (moveWheel > 0 && _buttonPos.y - _wheelSensitivity < _barPos.y )
		_buttonPos.y = _barPos.y + _wheelSensitivity;
	if (moveWheel < 0 && _buttonPos.y + _buttonSize.y + _wheelSensitivity > _barPos.y + _barSize.y )
		_buttonPos.y = _barPos.y + _barSize.y - _buttonSize.y - _wheelSensitivity;

	if ( moveWheel > 0)
		_buttonPos.y -= _wheelSensitivity;
	if ( moveWheel < 0)
		_buttonPos.y += _wheelSensitivity;
}
