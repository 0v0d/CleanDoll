#include "GalleryScene.h"
#include "SceneManager.h"

void GalleryScene::Initialize(){
	_barManager.Initialize();
	_galleryTexture.Initialize();
	
	_galleryTexture.CalcuBaseScale(_barManager.GetBackTextureSize().y);

	int space = 20;
	Vector2 barManagerPos = Vector2(g_pGraphics->GetTargetWidth()/2- _barManager.GetBackTextureSize().x-space, g_pGraphics->GetTargetHeight() / 2);
	_barManager.SetBasePos(barManagerPos);
	_galleryTexture.SetBasePos(Vector2(g_pGraphics->GetTargetWidth() / 2 + space, barManagerPos.y - _barManager.GetBackTextureSize().y / 2));

	_barManager.CreateBarArray();

	_music.Load("BGM.mp3");
}

void GalleryScene::ReLoad(){
	_barManager.ReLoad();
	_galleryTexture.ReLoad();
}


void GalleryScene::Update() {
	_barManager.Update();

	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) SceneManager::Instance().ChangeScene(SCENE_TYPE::TITLE);
}

void GalleryScene::SetMousePos(Vector2 mousePos){
	_barManager.SetMousePos(mousePos);
}

void GalleryScene::Push(){
	_barManager.Push();
	_galleryTexture.SetGalleryTexture(_barManager.GetPickTexture());
}

void GalleryScene::Pull(){
	_barManager.Pull();
}


void GalleryScene::Render(){
	_barManager.Render();
	_galleryTexture.Render();
}

void GalleryScene::Release(){
	_barManager.Release();
	_galleryTexture.Release();

	_music.Release();
}