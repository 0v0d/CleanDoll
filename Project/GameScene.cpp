#include "GameScene.h"


void GameScene::Initialize()
{
	_contactFile->GetCreateField()->SetField(&_field);
	_inputInGame.SetField(&_field);
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
	_inputInGame.Update();
	_field.Update();
}

void GameScene::Render()
{
	_backGround.Render();
	_field.Render();

	//CGraphicsUtilities::RenderString(30, 30, "Game");
}

void GameScene::Release()
{
	_gameBackTexture.Release();
	_field.Release();
}