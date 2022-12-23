#pragma once
#include	"Mof.h"
#include	"string"
#include	"GalleryBar.h"
#include	"ContactFile.h"
#include	"GetCoinNumber.h"

class GalleryBarManager
{
	const int _barValue = 5;
	GalleryBar* _barArray;
	int _gettedCoinValue;
	int* _requiredCoinValueArray;
	Vector2 _mousePos;

	Vector2 _backPos;
	CTexture _barBackGround;
	CTexture _barTexture, _lockTexture;

	ContactFile _contactFile;

	GetCoinNumber	_coinNumber;

public:
	void Initialize();
	void ReLoad();
	void SetBasePos(Vector2 centerPos);
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
	Vector2 GetBackTextureSize() { return Vector2(_barBackGround.GetWidth(),_barBackGround.GetHeight()); }

private:
	void LoadTexture();
	float CalcuBarScale(float space);
	float CalcuBarCenterPosY(int number,float space,float scale);
	void SetTexture();
	void PickUpBar();

	void SetBarData();
};