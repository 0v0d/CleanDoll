#include "GameScene.h"


void GameScene::Initialize()
{
	_gameBackTexture.Load("ÉQÅ[ÉÄÉvÉåÉCÅ@îwåiÅ@â¸ó«ÇP.png");
	_backGround.SetTextureStatus(&_gameBackTexture, REPEATSCREEN);
	_field.Initialize();
	_music.Load("BGM.mp3");
	_bgm.SetBGM(&_music, true);
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
}

void GameScene::Push() {
	_field.Push();
}

void GameScene::Pull() {
	_field.Pull();
}

void GameScene::Render()
{
	_backGround.Render();
	_field.Render();
}

void GameScene::Release()
{
	_gameBackTexture.Release();
	_field.Release();
	_music.Release();
}

void GameScene::StopBGM()
{
	_bgm.Stop();
}
