#include "GameScene.h"

void GameScene::Initialize()
{
	_contactFile->GetCreateField()->SetField(&_field);
	_inputInGaame.SetField(&_field);
	Load();
	_gameBackRect = CRectangle(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
	_field.Initialize();
}
void GameScene::Load()
{
	_gameBackTexture.Load("menu_back.png");
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
	_gameBackTexture.Render(0, 0, _gameBackRect);
	_field.Render();

	CGraphicsUtilities::RenderString(30, 30, "Game");
}

void GameScene::Release()
{
	_gameBackTexture.Release();
	_field.Release();
}