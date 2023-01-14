#include "GameScene.h"

void GameScene::Initialize()
{
	LoadTexture();

	_backGround.SetTextureStatus(&_gameBackTexture, REPEATSCREEN);
	_field.Initialize();
	_music.Load("BGM.mp3");
	_buttonSe.Load("BottanClick.mp3");

	_startAnimation.Initialize();

	_resetButtonPos = Vector2(g_pGraphics->GetTargetWidth() - _resetButtonTexture.GetWidth(), g_pGraphics->GetTargetHeight() - _resetButtonTexture.GetHeight());
	_resetStageButton.SetTexture(&_resetButtonTexture);
	_resetStageButton.SetSeSound(&_buttonSe);
	_resetStageButton.SetStatu(false, true, [&]() {_field.ReSetStage();});
}

void GameScene::LoadTexture() {
	_gameBackTexture.Load("GameBackGround.png");
	_resetButtonTexture.Load("reset_button.png");
}

void GameScene::ReLoad()
{
	_startAnimation.ReLoad();
	_slideInUI.SetPosition(_resetButtonPos.x, &_resetButtonPos.x, false);
	_field.ReLoad();
}

void GameScene::Update()
{
	_startAnimation.Update();
	_slideInUI.Update();
	_resetStageButton.SetPosition(_resetButtonPos);
	_field.Update();
}

void GameScene::SetMousePos(Vector2 mousePos) {
	_field.SetMousePos(mousePos);
	_resetStageButton.SetMousePos(mousePos);
}

void GameScene::Push() {
	if (!_startAnimation.IsEndAnimation()) return;
	_field.Push();
	_resetStageButton.Push();
}

void GameScene::Pull() {
	_field.Pull();
	_resetStageButton.Pull();
}

void GameScene::Render()
{
	_backGround.Render();
	_resetStageButton.Render();
	_field.Render();
	if(!_field.IsEndTutorial())return;
	_startAnimation.Render();
}

void GameScene::Release()
{
	_gameBackTexture.Release();
	_field.Release();
	_music.Release();
	_resetButtonTexture.Release();
	_buttonSe.Release();
	_startAnimation.Release();
}