#include "Button.h"

Button::Button() :
	_pushButton(false),
	_pullButton(false),
	_mouseOnButton(false),
	_scale(1)
{}

void Button::SetPosition(Vector2 buttonCenterPosition) {
	_centerPos.x = buttonCenterPosition.x;
	_centerPos.y = buttonCenterPosition.y;

	CalcuHitBox();
}

void Button::SetSize(float buttonSize) {
	CalcuScale(buttonSize);
}

void Button::CalcuScale(float buttonSize) {
	_scale = buttonSize / _texture->GetWidth();
	CalcuHitBox();
}

void Button::SetMousePos(Vector2 mousePosition) {
	CalcuHitBox();
	_mouseOnButton = CheckOnMouse(mousePosition);

	SetPullFlg(false);
}

void Button::CalcuHitBox() {
	float scale = _scale;
	if (_pushButton) scale /= _variableScale;
	else if (_mouseOnButton) scale *= _variableScale;

	_hitBox = CRectangle(_centerPos.x - _texture->GetWidth() * scale / 2, _centerPos.y - _texture->GetHeight() * scale / 2,
		_centerPos.x + _texture->GetWidth() * scale / 2, _centerPos.y + _texture->GetHeight() * scale / 2);
}

bool Button::CheckOnMouse(Vector2 mousePosition) {
	return _hitBox.CollisionPoint(mousePosition);
}


void Button::Push() {
	if (_mouseOnButton) _pushButton = true;
}

void Button::Pull() {
	if (_pushButton) {
		_pushButton = false;
		SetPullFlg(true);
	}
}


void Button::Render() {
	_pushButton ? _texture->Render(_hitBox, MOF_XRGB(200, 200, 200)) : _texture->Render(_hitBox);
}