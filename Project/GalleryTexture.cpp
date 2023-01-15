#include "GalleryTexture.h"

void GalleryTexture::Initialize(){
	LoadTexture();

	const  Vector2 space = Vector2(10, 250);
	_flamePos = Vector2(g_pGraphics->GetTargetWidth() / 2 + space.x, g_pGraphics->GetTargetHeight() / 2 - space.y);
}

void GalleryTexture::LoadTexture(){
	_backFlameTexture.Load("galleryflame.png");
}

void GalleryTexture::ReLoad(){
}

void GalleryTexture::SetGalleryTexture(CTexture* texture) {
	if (texture == nullptr) return;
	_galleryTexture = texture;
	CalcuGalleryScale();
	constexpr  float space = 22;
	_galleryPos = Vector2(_flamePos.x + space, _flamePos.y + space);
}

void GalleryTexture::CalcuGalleryScale() {
	_galleryScale = _backFlameTexture.GetHeight()  / _galleryTexture->GetHeight();
}

void GalleryTexture::Render(){
	_backFlameTexture.Render(_flamePos.x, _flamePos.y);
	if (_galleryTexture != nullptr){
		_galleryTexture->RenderScale(_galleryPos.x, _galleryPos.y, _galleryScale);
	}
}

void GalleryTexture::Release(){
	_backFlameTexture.Release();
}