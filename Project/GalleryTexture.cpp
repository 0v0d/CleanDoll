#include "GalleryTexture.h"

void GalleryTexture::Initialize(){
	LoadTexture();
}

void GalleryTexture::LoadTexture(){
	_backTexture.Load("stagepreview_base.png");
}

void GalleryTexture::CalcuBaseScale(float height) {
	_baseScale = height / _backTexture.GetHeight();
}

void GalleryTexture::ReLoad(){

}

void GalleryTexture::SetGalleryTexture(CTexture* texture) {
	if (texture == nullptr) return;
	_galleryTexture = texture;;
	CalcuGalleryScale();
	_galleryPos = _basePos;
}

void GalleryTexture::CalcuGalleryScale() {
	_galleryScale = _backTexture.GetHeight() * _baseScale / _galleryTexture->GetHeight();
}

void GalleryTexture::Render(){
	_backTexture.RenderScale(_basePos.x, _basePos.y, _baseScale);
	if (_galleryTexture != nullptr)_galleryTexture->RenderScale(_galleryPos.x, _galleryPos.y, _galleryScale);
	
}

void GalleryTexture::Release(){
	_backTexture.Release();
}