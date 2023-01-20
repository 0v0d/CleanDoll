#pragma once
#include	"IBaseAccessories.h"
class GalleryCoin :public IBaseAccessories
{
	CTexture _coinTexture;
	Vector2 _position;
	float _scale;

	ACCESSORIES_TYPE _accessoriesType;
public:
	GalleryCoin(ACCESSORIES_TYPE accessoriesType);
	void Initialize();
	void LoadTexture();
	void ReLoad();
	void CalcuScale(float blockSizeX) { _scale = blockSizeX / _coinTexture.GetWidth(); }
	void Update();
	void Render();
	void Release();
	void SetPosotion(Vector2 pos);
	ACCESSORIES_TYPE GetType() { return _accessoriesType; }
};