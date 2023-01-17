#include "GalleryTexture.h"

void GalleryTexture::Initialize(){
	LoadTexture();

	const  Vector2 supPos = Vector2(10, 250);
	_flamePos = Vector2(g_pGraphics->GetTargetWidth() / 2 + supPos.x, g_pGraphics->GetTargetHeight() / 2 - supPos.y);
	constexpr  float space = 22;
	_galleryPos = Vector2(_flamePos.x + space, _flamePos.y + space);
}

void GalleryTexture::LoadTexture(){
	_backFlameTexture.Load("galleryflame.png");
}

void GalleryTexture::ReLoad(){
}

void GalleryTexture::Push()
{

}

void GalleryTexture::Pull()
{

}

void GalleryTexture::SetGalleryTexture(CTexture* texture) {
	if (texture == nullptr) return;
	_galleryTexture = texture;
	_popUpTexture = texture;
	CalcuGalleryScale();
}

void GalleryTexture::CalcuGalleryScale() {
	_galleryScale = _backFlameTexture.GetHeight()  / _galleryTexture->GetHeight();
}

bool GalleryTexture::CheckPushGallery() {
	return ((_mousePos.x >= _galleryPos.x && _mousePos.x <= _galleryPos.x + _galleryTexture->GetWidth() * _galleryScale)&&
		(_mousePos.y >= _galleryPos.y && _mousePos.y <= _galleryPos.y + _galleryTexture->GetHeight() * _galleryScale));
}

void GalleryTexture::Render(){
	_backFlameTexture.Render(_flamePos.x, _flamePos.y);
	if (_galleryTexture != nullptr){
		_galleryTexture->RenderScale(_galleryPos.x, _galleryPos.y, _galleryScale);
	}
	if (_popUpTexture != nullptr&& _popUpShow) {
		constexpr float _scale = 1.4;
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(230, 0, 0, 0));
		_popUpTexture->RenderScale(g_pGraphics->GetTargetWidth() / 2 - _popUpTexture->GetWidth() * _scale / 2, g_pGraphics->GetTargetHeight() / 2 - _popUpTexture->GetHeight() * _scale / 2, _scale);
	}
}

void GalleryTexture::Release(){
	_backFlameTexture.Release();
}