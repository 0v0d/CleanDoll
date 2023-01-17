#pragma once
#include	"Mof.h"

class GalleryTexture
{
	CTexture _backFlameTexture;
	CTexture* _galleryTexture;
	CTexture* _popUpTexture = nullptr;
	Vector2 _flamePos,_galleryPos;
	Vector2 _mousePos;
	float _galleryScale;
	float _backTextureHeight;
	bool _popUpShow;
	bool _openedFlg;
public:
	void Initialize();
	void ReLoad();
	void Push();
	void Pull();

	void SetBackTextureHeight(float height) { _backTextureHeight = height; }
	void SetGalleryTexture(CTexture* texture);
	void SetMousePos(Vector2 mousePos) { _mousePos = mousePos; }
	void SetPopUpFlg(bool flg) { _popUpShow = flg; }
	void Render();
	void Release();

	bool IsPopUp()const { return _popUpShow; }
	bool CheckPushGallery();
private:
	void LoadTexture();
	void CalcuGalleryScale();
};