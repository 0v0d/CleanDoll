#include "TitleSceneTransition.h"
#include "StageSelectScene.h"
#include "SceneManager.h"

void TitleSceneTransition::Initialize() {
	LoadTexture();
	LoadSound();
	int ws = g_pGraphics->GetTargetWidth();
	CreateButton(&_transitionStageSelectButton, Vector2(ws / 2, 750), &_stageSelectTexture, [&]() {
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->CreateTutorialField();
		SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
		_transitionStageSelectButton.SetStatu(false, true, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);});
		});
	CreateButton(&_transitionGalleryButton, Vector2(ws / 2, 900), &_galleryTexture, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::GALLERY);});
	CreateButton(&_transitionCreditButton, Vector2(230, 1000), &_creditTexture, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::CREDIT); });
}

void TitleSceneTransition::LoadTexture() {
	_stageSelectTexture.Load("ÉQÅ[ÉÄÇénÇﬂÇÈ.png");
	_galleryTexture.Load("ÉMÉÉÉâÉäÅ[.png");
	_creditTexture.Load("ÉMÉÉÉâÉäÅ[.png");

	_buttonSe.Load("BottanClick.mp3");
}

void TitleSceneTransition::LoadSound() {
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
	_transitionCreditButton.SetMousePos(Vector2(0, 0));

}

void TitleSceneTransition::SetMousePos(Vector2 mousePos){
	_transitionStageSelectButton.SetMousePos(mousePos);
	_transitionGalleryButton.SetMousePos(mousePos);
	_transitionCreditButton.SetMousePos(mousePos);
}

void TitleSceneTransition::Push(){
	_transitionStageSelectButton.Push();
	_transitionGalleryButton.Push();
	_transitionCreditButton.Push();
}

void TitleSceneTransition::Pull() {
	_transitionStageSelectButton.Pull();
	_transitionGalleryButton.Pull();
	_transitionCreditButton.Pull();
}

void TitleSceneTransition::Render() {
	_transitionStageSelectButton.Render();
	_transitionGalleryButton.Render();
	_transitionCreditButton.Render();
}

void TitleSceneTransition::Release(){
	_stageSelectTexture.Release();
	_galleryTexture.Release();
	_creditTexture.Release();

	_buttonSe.Release();
}