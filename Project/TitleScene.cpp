#include "TitleScene.h"
#include "SceneManager.h"

void TitleScene::Initialize()
{
	_titleLogoAnimation.Initialize();
	_titleClickAnimation.Initialize();

	_titleBackTexture.Load("titleback.png");
	_backGround.SetTextureStatus(&_titleBackTexture, FULLSCREEN);

	_music.Load("BGM.mp3");
	_bgm.SetBGM(&_music, true);
	_bgm.Play();
}

void TitleScene::ReLoad()
{
	_bgm.Play();
	_titleLogoAnimation.ReLoad();
	_titleClickAnimation.ReLoad();
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
	SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	_bgm.Stop();
}

void TitleScene::Pull() {

}

void TitleScene::Render()
{
	_backGround.Render();
	_titleLogoAnimation.Render();
	_titleClickAnimation.Render();
}

void TitleScene::Release()
{
	_titleLogoAnimation.Release();
	_titleClickAnimation.Release();
	_titleBackTexture.Release();

	_music.Release();
}

void TitleScene::StopBGM()
{
	_bgm.Stop();
}