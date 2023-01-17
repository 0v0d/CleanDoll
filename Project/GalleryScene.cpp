#include "GalleryScene.h"
#include "SceneManager.h"

void GalleryScene::Initialize(){

	LoadTexture();
	_backGround.SetTextureStatus(&_backGroundTexture, FULLSCREEN);
	_barManager.Initialize();
	_barManager.CreateBarArray();

	_galleryTexture.Initialize();
	_galleryTexture.SetBackTextureHeight(_barManager.GetBackTextureSize().y);

	_titleButton.SetTexture(&_buttonTexture);
	_titleButton.SetPosition(Vector2(100, 100));
	_titleButton.SetSeSound(&_buttonSe);
	_titleButton.SetStatu(false, true, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::TITLE);});

	//デバッグ
	AddCoin();
	AddCoin();
}

void GalleryScene::LoadTexture() {
	_music.Load("BGM.mp3");
	_buttonSe.Load("BottanClick.mp3");
	_buttonTexture.Load("backSceneButton.png");
	_backGroundTexture.Load("galleryBack.png");
}

void GalleryScene::ReLoad(){
	_barManager.ReLoad();
	_galleryTexture.ReLoad();

	_galleryTexture.SetGalleryTexture(_barManager.GetGalleryTexture(0));
}

void GalleryScene::Update() {
	_barManager.Update();
}

void GalleryScene::SetMousePos(Vector2 mousePos){
	_barManager.SetMousePos(mousePos);
	_titleButton.SetMousePos(mousePos);
	_galleryTexture.SetMousePos(mousePos);
}

void GalleryScene::Push(){
	
	if (_galleryTexture.IsPopUp()) {
		_galleryTexture.SetPopUpFlg(false);
	}
	else {
		_barManager.Push();
		_titleButton.Push();
		_galleryTexture.Push();

		_galleryTexture.SetGalleryTexture(_barManager.GetMouseOnBarTexture());
		if (_galleryTexture.CheckPushGallery() && !_barManager.IsLockedPopUpTexture()) {
			_galleryTexture.SetPopUpFlg(true);
		}
	}
}

void GalleryScene::Pull(){
	_galleryTexture.Pull();
	if (_galleryTexture.IsPopUp())return;
	_barManager.Pull();
	_titleButton.Pull();
}

void GalleryScene::Render(){
	_backGround.Render();
	_barManager.Render();
	_titleButton.Render();
	_galleryTexture.Render();
}

void GalleryScene::Release(){
	_barManager.Release();
	_galleryTexture.Release();
	_music.Release();
	_buttonSe.Release();
	_buttonTexture.Release();
	_backGroundTexture.Release();
}