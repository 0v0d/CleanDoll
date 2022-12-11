#pragma once
#include	"IBaseScene.h"
#include	"GalleryBarManager.h"
#include	"GalleryTexture.h"
class GalleryScene :public IBaseScene
{
	GalleryBarManager _barManager;
	GalleryTexture _galleryTexture;
public:
	void Initialize();
	void ReLoad();

	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void Update();
	void AddCoin();

	void Render();
	void Release();
	void StopBGM() {}
};