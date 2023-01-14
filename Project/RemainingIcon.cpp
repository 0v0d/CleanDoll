#include "RemainingIcon.h"

void RemainingIcon::SetTexture(CTexture* icon, CTexture* mark, CTexture* notExist) {
	_iconTexture = icon;
	_markTexture = mark;
	_notExistTexture = notExist;
}

void RemainingIcon::SetScale(float scale) {
	_scale = scale;
}

void RemainingIcon::SetPosition(Vector2 pos) {
	_position.x = pos.x;
	_position.y = pos.y - _iconTexture->GetWidth() * _scale;

	CalcuMarkPosition();
}

void RemainingIcon::CalcuMarkPosition() {
	_markPosition.x = _position.x + (_iconTexture->GetWidth() - _markTexture->GetWidth()) / 2 * _scale;
	_markPosition.y = _position.y + (_iconTexture->GetHeight() - _markTexture->GetHeight()) / 2 * _scale;
}

void RemainingIcon::ReLoad() {
	_mark = false;
	_slideInUI.SetPosition(_position.x,&_position.x,true);
}

void RemainingIcon::Update()
{
	_slideInUI.Update();
}

void RemainingIcon::Render() {
	_iconTexture->RenderScale(_position.x, _position.y, _scale);

	if (_notExist)_notExistTexture->RenderScale(_position.x, _position.y, _scale);
	else if (_mark)_markTexture->RenderScale(_markPosition.x, _markPosition.y, _scale);
}
