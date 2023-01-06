#include "TitleScene.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void TitleScene::Initialize()
{
	_titleLogoAnimation.Initialize();
	_titleClickAnimation.Initialize();

	_titleBackTexture.Load("titleback.png");
	_backGround.SetTextureStatus(&_titleBackTexture, FULLSCREEN);

	_music.Load("BGM.mp3");
	_clearTutorial = false;
}

void TitleScene::ReLoad()
{
	_titleLogoAnimation.ReLoad();
	_titleClickAnimation.ReLoad();
	_clearTutorial = true;
}

void TitleScene::Update()
{
	_titleLogoAnimation.Update();
	_titleClickAnimation.Update();
	//デバッグ
	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) SceneManager::Instance().ChangeScene(SCENE_TYPE::GALLERY);
}

void TitleScene::SetMousePos(Vector2 mousePos) {
}

void TitleScene::Push() {
}

void TitleScene::Pull() {
	if (!_clearTutorial) {
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->CreateTutorialField();
		SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
	}
	else {

		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void TitleScene::Render()
{
	_backGround.Render();
	_titleClickAnimation.Render();
	_titleLogoAnimation.Render();
}

void TitleScene::Release()
{
	_titleLogoAnimation.Release();
	_titleClickAnimation.Release();
	_titleBackTexture.Release();

	_music.Release();
}