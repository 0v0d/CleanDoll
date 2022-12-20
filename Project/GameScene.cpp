#include "GameScene.h"

void GameScene::Initialize()
{
	LoadTexture();

	_backGround.SetTextureStatus(&_gameBackTexture, REPEATSCREEN);
	_field.Initialize();
	_music.Load("BGM.mp3");
	_bgm.SetBGM(&_music, true);
	_tutorial.Initialize();
	_field.SetInputLimitArray(_tutorial.GetInputLimitArray());
	_field.SetInputLimitValue(_tutorial.GetInputLimitValue());
	_field.SetTutorialRouteArray(_tutorial.GetTutorialRouteArray());
	_field.SetTutorialRoute(_tutorial.GetTutorialRoute()->first,_tutorial.GetTutorialRoute()->second);
	_field.SetTutorialArrayMaxValue(_tutorial.GetRouteValue());
	
	
}

void GameScene::LoadTexture() {
	_gameBackTexture.Load("GameBackGround.png");
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
