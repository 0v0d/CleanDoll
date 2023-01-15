#pragma once
#include	"Mof.h"

class GalleryTexture
{
	CTexture _backFlameTexture;
	CTexture* _galleryTexture = nullptr;
	Vector2 _flamePos,_galleryPos;
	float _galleryScale;
	float _backTextureHeight;
public:
	void Initialize();
	void ReLoad();
	
	void SetBackTextureHeight(float height) { _backTextureHeight = height; }
	void SetGalleryTexture(CTexture* texture);
	
	void Render();
	void Release();

private:
	void LoadTexture();
	void CalcuGalleryScale();
};