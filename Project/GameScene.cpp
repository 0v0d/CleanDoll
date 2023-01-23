#include "GameScene.h"

void GameScene::Initialize()
{
	LoadTexture();
	LoadSound();
	_backGround.SetTextureStatus(&_gameBackTexture, REPEATSCREEN);
	_field.Initialize();
	

	_startAnimation.Initialize();

	_resetButtonPos = Vector2(g_pGraphics->GetTargetWidth() - _resetButtonTexture.GetWidth(), g_pGraphics->GetTargetHeight() - _resetButtonTexture.GetHeight());
	_slideInUI.SetStatu(_resetButtonPos.x, &_resetButtonPos.x, false);
	_slideInUI.Start();

	_resetStageButton.SetTexture(&_resetButtonTexture);
	_resetStageButton.SetSeSound(&_buttonSe);
	_resetStageButton.SetStatu(false, true, [&]() {
		_field.PushResetButton();
		_field.ReSetStage();
		});

	_slideUI = false;
}

void GameScene::LoadTexture() {
	_gameBackTexture.Load("GameBackGround.png");
	_resetButtonTexture.Load("reset_button.png");
}

void GameScene::LoadSound() {
	_music.Load("BGM.mp3");
	_buttonSe.Load("BottanClick.mp3");
}

void GameScene::ReLoad()
{
	_field.ReLoad();
	if(_field.IsEndTutorial()) _slideUI = true;
}

void GameScene::Update()
{
	_startAnimation.Update();
	_slideInUI.Update();
	_resetStageButton.SetPosition(_resetButtonPos);
	_field.Update();

	if (_slideUI && _slideInUI.IsEnd()) {
		if (_field.IsEndTutorial()) {
			_startAnimation.StartCleanAnimation();
			_slideUI = false;
		}
	}
}

void GameScene::SetMousePos(Vector2 mousePos) {
	_field.SetMousePos(mousePos);
	_resetStageButton.SetMousePos(mousePos);
}

void GameScene::Push() {
	if (!_startAnimation.IsEndAnimation()) return;
	_field.Push();
	if (!_field.IsEndProcess()) {
		_resetStageButton.Push();
	}
}

void GameScene::Pull() {
	_field.Pull();
	if (!_field.IsEndProcess()) {
		_resetStageButton.Pull();
	}
}

void GameScene::Render()
{
	_backGround.Render();
	_resetStageButton.Render();
	_field.Render();
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