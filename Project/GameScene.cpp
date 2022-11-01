#include "GameScene.h"

void GameScene::Initialize()
{
	_contactFile->GetCreateField()->SetField(&_field);
	_inputInGaame.SetField(&_field);

	_field.Initialize();
}

void GameScene::ReLoad()
{
	_field.ReLoad();
}

void GameScene::Update()
{
	_inputInGaame.Update();
	_field.Update();
}

void GameScene::Render()
{
	_field.Render();

	CGraphicsUtilities::RenderString(30, 30, "Game");
}

void GameScene::Release()
{
	_field.Release();
}