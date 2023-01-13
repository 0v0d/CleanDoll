#include "TitleSceneTransition.h"
#include "StageSelectScene.h"
#include "SceneManager.h"

void TitleSceneTransition::Initialize() {
	LoadTexture();
	
	int ws = g_pGraphics->GetTargetWidth();
	CreateButton(&_transitionStageSelectButton, Vector2(ws / 2, 750), &_stageSelectTexture, [&]() {
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->CreateTutorialField();
		SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
		});
	CreateButton(&_transitionGalleryButton, Vector2(ws / 2, 900), &_galleryTexture, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::GALLERY);});
}

void TitleSceneTransition::LoadTexture() {
	_stageSelectTexture.Load("ÉQÅ[ÉÄÇénÇﬂÇÈ.png");
	_galleryTexture.Load("ÉMÉÉÉâÉäÅ[.png");

	_buttonSe.Load("BottanClick.mp3");
}

void TitleSceneTransition::CreateButton(Button* button,Vector2 pos, CTexture* tx, std::function<void()> method) {
	button->SetTexture(tx);
	button->SetPosition(pos);
	button->SetSeSound(&_buttonSe);
	button->SetStatu(false, true, method);
}


void TitleSceneTransition::ReLoad(){
	_transitionStageSelectButton.SetMousePos(Vector2(0,0));
	_transitionGalleryButton.SetMousePos(Vector2(0, 0));

	_transitionStageSelectButton.SetStatu(false, true, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);});
}

void TitleSceneTransition::SetMousePos(Vector2 mousePos){
	_transitionStageSelectButton.SetMousePos(mousePos);
	_transitionGalleryButton.SetMousePos(mousePos);
}

void TitleSceneTransition::Push(){
	_transitionStageSelectButton.Push();
	_transitionGalleryButton.Push();
}

void TitleSceneTransition::Pull() {
	_transitionStageSelectButton.Pull();
	_transitionGalleryButton.Pull();
}

void TitleSceneTransition::Render() {
	_transitionStageSelectButton.Render();
	_transitionGalleryButton.Render();
}

void TitleSceneTransition::Release(){
	_stageSelectTexture.Release();
	_galleryTexture.Release();

	_buttonSe.Release();
}