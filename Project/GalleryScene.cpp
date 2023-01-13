#include "GalleryScene.h"
#include "SceneManager.h"

void GalleryScene::Initialize() {

	LoadTexture();

	_barManager.Initialize();
	_galleryTexture.Initialize();

	_galleryTexture.CalcuBaseScale(_barManager.GetBackTextureSize().y);

	int space = 20;
	Vector2 barManagerPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _barManager.GetBackTextureSize().x - space, g_pGraphics->GetTargetHeight() / 2);
	_barManager.SetBasePos(barManagerPos);
	_galleryTexture.SetBasePos(Vector2(g_pGraphics->GetTargetWidth() / 2 + space, barManagerPos.y - _barManager.GetBackTextureSize().y / 2));

	_barManager.CreateBarArray();

	_titleButton.SetTexture(&_buttonTexture);
	_titleButton.SetPosition(Vector2(barManagerPos.x, 100));
	_titleButton.SetSeSound(&_buttonSe);
	_titleButton.SetStatu(false, true, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::TITLE);});
}

void GalleryScene::LoadTexture() {
	_music.Load("BGM.mp3");
	_buttonSe.Load("BottanClick.mp3");
	_buttonTexture.Load("チェックボックス.png");
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

}

void GalleryScene::Push(){
	_barManager.Push();
	_galleryTexture.SetGalleryTexture(_barManager.GetPickTexture());
	_titleButton.Push();
}

void GalleryScene::Pull(){
	_barManager.Pull();
	_titleButton.Pull();
}


void GalleryScene::Render(){
	_barManager.Render();
	_galleryTexture.Render();
	_titleButton.Render();
}

void GalleryScene::Release(){
	_barManager.Release();
	_galleryTexture.Release();

	_music.Release();
	_buttonSe.Release();
	_buttonTexture.Release();
}