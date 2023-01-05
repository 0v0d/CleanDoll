#include "Button.h"

Button::Button(){
	_push = _pull = _mouseOnButton = false;
	_pushCallMethod = _pullCallMethod = false;
	_scale = 1;
}

void Button::SetStatu(bool push, bool pull, std::function<void()> callMethod) {
	_pushCallMethod = push;
	_pullCallMethod = pull;

	_callMethod = callMethod;
}

void Button::SetPosition(Vector2 buttonCenterPosition) {
	_centerPos.x = buttonCenterPosition.x;
	_centerPos.y = buttonCenterPosition.y;

	CalcuHitBox();
}

void Button::CalcuScale(float sizeX, float sizeY) {

	if (sizeX != 0) _scale = sizeX / _texture->GetWidth();
	if (sizeY != 0) _scale = sizeY / _texture->GetHeight();

	CalcuHitBox();
}

void Button::SetMousePos(Vector2 mousePosition) {
	CalcuHitBox();
	_mouseOnButton = CheckOnMouse(mousePosition);

	_pull = false;
}

void Button::CalcuHitBox() {
	float scale = _scale;
	if (_push) scale /= _variableScale;
	else if (_mouseOnButton) scale *= _variableScale;

	_hitBox = CRectangle(_centerPos.x - _texture->GetWidth() * scale / 2, _centerPos.y - _texture->GetHeight() * scale / 2,
		_centerPos.x + _texture->GetWidth() * scale / 2, _centerPos.y + _texture->GetHeight() * scale / 2);
}

bool Button::CheckOnMouse(Vector2 mousePosition) {
	return _hitBox.CollisionPoint(mousePosition);
}


void Button::Push() {
	if (_mouseOnButton) _push = true;
	if (_pushCallMethod) {
		_callMethod();
		_se.Play();
	}
}

void Button::Pull() {
	if (_push && _mouseOnButton) {
		_pull = true;
	}
	_push = false;

	if (_pull&&_pullCallMethod) {
		_callMethod();
		_se.Play();
	}
}


void Button::Render() {
	_push ? _texture->Render(_hitBox, MOF_XRGB(200, 200, 200)) : _texture->Render(_hitBox);
}