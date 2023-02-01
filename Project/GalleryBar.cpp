#include "GalleryBar.h"

void GalleryBar::Initialize() {
}

void GalleryBar::ReLoad() {
}

void GalleryBar::SetBaseTexture(CTexture* texture) {
	_baseTexture = texture;
}

void GalleryBar::CalcuRect(int number, int maxNumber, bool lock) {

	Vector2 size = Vector2(_baseTexture->GetWidth() / (maxNumber * 2), _baseTexture->GetHeight());
	float lockPos = lock ?  _baseTexture->GetWidth() / 2 : 0;
	_renderRect = CRectangle(size.x * number + lockPos, 0, size.x * (number + 1) + lockPos, size.y);
}

void GalleryBar::CalcuPos() {
	_pos.x = _centerPos.x - (_renderRect.Right - _renderRect.Left) * _scale / 2;
	_pos.y = _centerPos.y - (_renderRect.Bottom - _renderRect.Top) * _scale / 2;
}

void GalleryBar::Update() {
}

void GalleryBar::PickUpFlg(bool flg) {
	_pickUp = flg;
	_scale = flg ? _baseScale * _largeScale : _baseScale;
	CalcuPos();
}

bool GalleryBar::CheckOnMouse(Vector2 mousePos) {
	CRectangle rect = CRectangle(_pos.x, _pos.y, _pos.x + (_renderRect.Right - _renderRect.Left) * _scale, _pos.y + _baseTexture->GetHeight() * _scale);
	return rect.CollisionPoint(mousePos);
}


void GalleryBar::Render() {
	_baseTexture->RenderScale(_pos.x, _pos.y, _scale, _renderRect);
}

void GalleryBar::Release() {
}