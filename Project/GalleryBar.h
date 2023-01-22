#pragma once
#include	"Mof.h"

class GalleryBar
{
	Vector2 _pos, _centerPos;
	CTexture* _baseTexture;
	float _baseScale, _scale;
	const float _largeScale = 1.1f;
	bool _pickUp;
	CRectangle _renderRect;

public:
	void Initialize();
	void ReLoad();
	void SetBaseScale(float scale) { _baseScale = _scale = scale; }
	void SetCenterPos(Vector2 centerPos) { _centerPos = centerPos; }
	void SetBaseTexture(CTexture* texture);
	void CalcuRect(int number, int maxNumber,bool lock);
	void CalcuPos();

	void Update();
	void PickUpFlg(bool flg);
	void Render();
	void Release();
	bool CheckOnMouse(Vector2 mousePos);
	bool IsPickUp() const{return _pickUp;}
};