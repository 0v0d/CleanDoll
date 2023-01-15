#pragma once
#include	"Mof.h"
#include	"string"
#include	"GalleryBar.h"
#include	"ContactFile.h"
#include	"GetCoinNumber.h"
#include "Trim.h"

class GalleryBarManager
{
	Trim _trimstring;
	const int _barValue = 4;
	GalleryBar* _barArray;
	int _gettedCoinValue;
	int* _requiredCoinValueArray;
	Vector2 _mousePos;

	Vector2 _backPos;
	CTexture _barBackGround;

	ContactFile _contactFile;

	GetCoinNumber	_coinNumber;
	CTexture* _lockedBarTexureArray;
	CTexture* _openedBarTexureArray;
public:
	void Initialize();
	void ReLoad();
	void CreateBarArray();

	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void Update();
 	void AddCoinValue() { 
		_gettedCoinValue++; 
		_coinNumber.SetCoinNumberValue(_gettedCoinValue);
	}

	void Render();
	void Release();

	CTexture* GetPickTexture();
	Vector2 GetBackTextureSize() const { return Vector2(_barBackGround.GetWidth(),_barBackGround.GetHeight()); }

private:
	void LoadTexture();
	float CalcuBarScale(float space);
	float CalcuBarCenterPosY(int number,float space,float scale);
	void SetTexture();
	void PickUpBar();

	void SetBarData();

	void LoadLockedTexture();
	void LoadOpenedTexture();
};
