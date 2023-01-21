#pragma once
#include	"IBaseAccessories.h"
class GalleryCoin :public IBaseAccessories
{
	CTexture _coinTexture;
	Vector2 _position;
	float _scale;
	float _time;
	float _incPosY;

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
	//y=sin(1/2xƒÎ)+1
	void CalcPosY();
};