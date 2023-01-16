#include "GalleryScene.h"
#include "SceneManager.h"

void GalleryScene::Initialize(){

	LoadTexture();
	_backGround.SetTextureStatus(&_backGroundTexture, FULLSCREEN);
	_barManager.Initialize();
	_barManager.CreateBarArray();

	_galleryTexture.Initialize();
	_galleryTexture.SetBackTextureHeight(_barManager.GetBackTextureSize().y);
	_galleryTexture.SetGalleryTexture(_barManager.GetPickTexture());

	_titleButton.SetTexture(&_buttonTexture);
	_titleButton.SetPosition(Vector2(100, 100));
	_titleButton.SetSeSound(&_buttonSe);
	_titleButton.SetStatu(false, true, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::TITLE);});
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
	_galleryTexture.SetGalleryTexture(_barManager.GetPickTexture());
	_galleryTexture.SetPopUpTexture(_barManager.GetOpenedTexture());
	_galleryTexture.Push();
	if (_galleryTexture.IsPopUp())return;
	_barManager.Push();
	_titleButton.Push();
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