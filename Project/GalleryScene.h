#pragma once
#include	"IBaseScene.h"
#include	"GalleryBarManager.h"
#include	"GalleryTexture.h"
#include	"Button.h"

class GalleryScene :public IBaseScene
{
	GalleryBarManager _barManager;
	GalleryTexture _galleryTexture;
	CSoundBuffer _music;

	Button _titleButton;
	CSoundBuffer _buttonSe;
	CTexture _buttonTexture;

public:
	void Initialize();
	void ReLoad();

	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void Update();
	void AddCoin() { _barManager.AddCoinValue();}

	void Render();
	void Release();
	CSoundBuffer* GetBGM() { return &_music; }

private:
	void LoadTexture();
};