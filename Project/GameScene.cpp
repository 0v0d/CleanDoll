#include "GameScene.h"


void GameScene::Initialize()
{
	_gameBackTexture.Load("menu_back.png");
	_backGround.SetTextureStatus(&_gameBackTexture, REPEATSCREEN);
	_field.Initialize();
}

void GameScene::ReLoad()
{
	_field.ReLoad();
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
}