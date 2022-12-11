#pragma once
#include	"Mof.h"

class GalleryTexture
{
	CTexture _backTexture;
	CTexture* _galleryTexture = nullptr;
	Vector2 _basePos,_galleryPos;
	float _baseScale, _galleryScale;

public:
	void Initialize();
	void ReLoad();
	void SetBasePos(Vector2 pos) { _basePos = pos; }
	void CalcuBaseScale(float height);
	void SetGalleryTexture(CTexture* texture);
	
	void Render();
	void Release();

private:
	void LoadTexture();
	void CalcuGalleryScale();
};