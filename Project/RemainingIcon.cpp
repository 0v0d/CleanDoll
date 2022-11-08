#include "RemainingIcon.h"

void RemainingIcon::SetTexture(CTexture* icon, CTexture* mark, CTexture* notExist) {
	_iconTexture = icon;
	_markTexture = mark;
	_notExistTexture = notExist;
}

void RemainingIcon::SetPosition(Vector2 pos) {
	_position.x = pos.x;
	_position.y = pos.y - _iconTexture->GetWidth() * _scale;
}

void RemainingIcon::ReLoad() {
	_mark = _notExist = false;
}

void RemainingIcon::Render() {
	_iconTexture->RenderScale(_position.x, _position.y, _scale);

	if (_notExist)_notExistTexture->RenderScale(_position.x, _position.y, _scale);
	else if (_mark)_markTexture->RenderScale(_position.x, _position.y, _scale);
}