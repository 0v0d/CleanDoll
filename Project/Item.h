#pragma once
#include	"Mof.h"
#include	"IBaseAccessories.h"

class Item :public IBaseAccessories
{
private:
	CTexture* _itemTexture;
	Vector2 _position;
	float _scale;
	ACCESSORIES_TYPE _accessoriesType;
public:
	Item(CTexture* itemTexture, ACCESSORIES_TYPE accessoriesType);
	void Initialize();
	void ReLoad();
	void CalcuScale(float blockSizeX) { _scale = blockSizeX / _itemTexture->GetWidth(); }
	void Update();
	void Render();
	void Release();
	void SetPosotion(Vector2 pos);
	ACCESSORIES_TYPE GetType() { return _accessoriesType; }
};