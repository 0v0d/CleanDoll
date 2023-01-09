#include "GameClearButton.h"

void GameClearButton::Initialize() {
	Load();
	CreateButton();
}

void GameClearButton::Load() {
	_clearButtonTexture.Load("clearButton.png");
	_buttonSe.Load("ClicktoStart.mp3");
}

void GameClearButton::CreateButton() {
	_button.SetTexture(&_clearButtonTexture);
	_button.SetPosition(Vector2(_clearButtonTexture.GetWidth() , _clearButtonTexture.GetHeight() / 3));
	_button.SetSeSound(&_buttonSe);
	_button.SetStatu(false, true, [&]() {_pull = true;});
}

void GameClearButton::ReLoad() {
	_show = false;
	_pull = false;
}

void GameClearButton::SetMousePos(Vector2 mousePos) {
	_button.SetMousePos(mousePos);
}

void GameClearButton::Push() {
	if (!_show)return;
	_button.Push();
}

void GameClearButton::Pull() {
	if(!_show)return;
	_button.Pull();
}

void GameClearButton::Update() {
	if(_dustValue <= 0 && _waterValue <= 0) _show = true;
}

void GameClearButton::Render() {
	if(_show) _button.Render();
}

void GameClearButton::Release() {
	_clearButtonTexture.Release();
	_buttonSe.Release();
}
