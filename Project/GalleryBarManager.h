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

	Vector2 _backPos = Vector2(70, 300);
	Vector2 _barBackSize = Vector2(750, 750);

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
	CTexture _barTexture;

	bool _lockedPopUpTexture;
public:
	void Initialize();
	void ReLoad();

	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void Update();
	void AddCoinValue();

	void Render();
	void Release();

	CTexture* GetMouseOnBarTexture();
	CTexture* GetGalleryTexture(int number);
	Vector2 GetBackTextureSize() { return _barBackSize; }
	bool IsLockedPopUpTexture() { return _lockedPopUpTexture; }
private:
	void LoadTexture();
	float CalcuBarScale(float space);
	float CalcuBarCenterPosY(int number,float space,float scale);
	void PickUpBar();
	void CreateBarArray();

	void LoadGalleryTexture();
};
