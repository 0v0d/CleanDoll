#include "GameScene.h"

void GameScene::Initialize()
{
	LoadTexture();

	_backGround.SetTextureStatus(&_gameBackTexture, REPEATSCREEN);
	_field.Initialize();
	_music.Load("BGM.mp3");
	_bgm.SetBGM(&_music, true);

	_resetStageButton.SetTexture(&_resetButtonTexture);
	_resetStageButton.SetPosition(Vector2(100, 130));

}

void GameScene::LoadTexture() {
	_gameBackTexture.Load("GameBackGround.png");
	_resetButtonTexture.Load("reset_button.png");
}

void GameScene::ReLoad()
{
	_field.ReLoad();
	_bgm.Play();
}

void GameScene::Update()
{
	_field.Update();
}

void GameScene::SetMousePos(Vector2 mousePos) {
	_field.SetMousePos(mousePos);
	_resetStageButton.SetMousePos(mousePos);
}

void GameScene::Push() {
	_field.Push();
	_resetStageButton.Push();
}

void GameScene::Pull() {
	_field.Pull();
	_resetStageButton.Pull();
	if (_resetStageButton.IsPullButton()) _field.ReLoad();
}

void GameScene::Render()
{
	_backGround.Render();
	_field.Render();
	_resetStageButton.Render();
}

void GameScene::Release()
{
	_gameBackTexture.Release();
	_field.Release();
	_music.Release();
	_resetButtonTexture.Release();
}

void GameScene::StopBGM()
{
	_bgm.Stop();
}
