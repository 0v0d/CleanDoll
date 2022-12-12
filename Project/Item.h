#pragma once
#include	"Mof.h"
#include	"IBaseAccessories.h"

class Item :public IBaseAccessories
{
private:
	CTexture* _itemTexture;
	Vector2 _position;
	float _scale;
	bool _show;
	ACCESSORIES_TYPE _accessoriesType;
public:
	Item(CTexture* itemTexture, ACCESSORIES_TYPE accessoriesType);
	void Initialize();
	void ReLoad();
	void CalcuScale(float blockSizeX) { _scale = blockSizeX / _itemTexture->GetWidth(); }
	void SetShow(bool show) { _show = show; }
	void Update();
	void Render();
	void Release();
	void SetPosotion(Vector2 pos);
	ACCESSORIES_TYPE GetType() { return _accessoriesType; }
};