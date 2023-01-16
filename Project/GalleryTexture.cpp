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

void GalleryTexture::Push()
{
	
}

void GalleryTexture::Pull()
{
	if (_popUpShow) {
		_popUpShow = false;
	}
	else{
		CRectangle galleryTextureRect = CRectangle(_galleryPos.x, _galleryPos.y,
			_galleryPos.x + _galleryTexture->GetWidth(), _galleryPos.y + _galleryTexture->GetHeight());
		if (galleryTextureRect.CollisionPoint(_mousePos)) {
			_popUpShow = true;
		}
	}

}

void GalleryTexture::SetGalleryTexture(CTexture* texture) {
	if (texture == nullptr) return;
	_galleryTexture = texture;
	CalcuGalleryScale();
	constexpr  float space = 22;
	_galleryPos = Vector2(_flamePos.x + space, _flamePos.y + space);
}

void GalleryTexture::SetPopUpTexture(CTexture* texture)
{
	if (texture == nullptr) return;
	_popUpTexture = texture;
}

void GalleryTexture::CalcuGalleryScale() {
	_galleryScale = _backFlameTexture.GetHeight()  / _galleryTexture->GetHeight();
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
	CGraphicsUtilities::RenderString(100, 100, "%d", _popUpShow);

}

void GalleryTexture::Release(){
	_backFlameTexture.Release();
}