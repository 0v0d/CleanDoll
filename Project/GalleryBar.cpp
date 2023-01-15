#include "GalleryBar.h"

void GalleryBar::Initialize() {
}

void GalleryBar::ReLoad() {
}

void GalleryBar::SetBaseTexture(CTexture* texture) {
	_baseTexture = texture;
	CalcuPosition();
}

void GalleryBar::CalcuPosition() {
	_pos.x = _centerPos.x - _baseTexture->GetWidth() * _scale / 2;
	_pos.y = _centerPos.y - _baseTexture->GetHeight() * _scale / 2;
}

void GalleryBar::Update() {
}

void GalleryBar::PickUpFlg(bool flg) {
	_pickUp = flg;
	_scale = flg ? _baseScale * _largeScale : _baseScale;
	CalcuPosition();
}

bool GalleryBar::CheckOnMouse(Vector2 mousePos) {
	CRectangle rect = CRectangle(_pos.x, _pos.y, _pos.x + _baseTexture->GetWidth() * _scale, _pos.y + _baseTexture->GetHeight() * _scale);
	return rect.CollisionPoint(mousePos);
}


void GalleryBar::Render() {
	_baseTexture->RenderScale(_pos.x, _pos.y, _scale);
}

void GalleryBar::Release() {
}