#pragma once
#include	"Mof.h"
#include	"GalleryBar.h"
#include	"ContactFile.h"
#include	"Number.h"
#include	"Trim.h"

class GalleryBarManager
{
	Trim _trimstring;
	const int _barValue = 4;
	GalleryBar* _barArray;
	int _gotCoinValue;
	int* _requiredCoinValueArray;
	Vector2 _mousePos;

	Vector2 _backPos;
	CTexture _barBackGround;

	ContactFile _contactFile;

	CTexture* _lockedBarTexureArray;
	CTexture* _openedBarTexureArray;
	CTexture* _lockedTexureArray;
	CTexture* _openedTexureArray;

	Number	_coinNumber;
	Number	_maxCoinValue;
	const int _numberValue = 11;
	const float _numberScale = 0.3f;
	CTexture _numberTexture;
public:
	void Initialize();
	void ReLoad();
	void CreateBarArray();

	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void Update();
	void AddCoinValue();

	void Render();
	void Release();

	CTexture* GetPickTexture();
	CTexture* GetOpenedTexture();
	Vector2 GetBackTextureSize() const { return Vector2(_barBackGround.GetWidth(),_barBackGround.GetHeight()); }
private:
	void LoadTexture();
	float CalcuBarScale(float space);
	float CalcuBarCenterPosY(int number,float space,float scale);
	void SetTexture();
	void PickUpBar();

	void LoadRequiredCoinValue();
	void LoadGalleryTexture();
	void LoadBarTexture();
};
