#pragma once
#include	"Mof.h"
#include	"string"

class GalleryBar
{
	Vector2 _pos, _centerPos;
	CTexture* _baseTexture;
	CTexture _lockedTextTexture;
	CTexture _galleryTexture;
	float _baseScale, _scale;
	const float _largeScale = 1.1f;
	bool _watch,_pickUp;

public:
	GalleryBar();

	void Initialize();
	void ReLoad();
	void SetBaseScale(float scale) { _baseScale = _scale = scale; }
	void SetCenterPos(Vector2 centerPos) { _centerPos = centerPos; }
	void SetBaseTexture(CTexture* texture);
	void SetLockedTextTexture(std::string textureName) { _lockedTextTexture.Load(textureName.c_str()); }
	void SetGalleryTexture(std::string textureName) { _galleryTexture.Load(textureName.c_str()); }

	void Update();
	void PickUpFlg(bool flg);
	void CanWatch() { _watch = true; }

	void Render();
	void Release();

	bool CheckOnMouse(Vector2 mousePos);
	CTexture* GetGaleryTexture() { return &_galleryTexture; }
	bool IsPickUp() {return _pickUp;}

private:
	void CalcuPosition();
};