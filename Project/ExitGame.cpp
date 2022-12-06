#include "ExitGame.h"


void ExitGame::Initialize() {
	_basePos.x = g_pGraphics->GetTargetWidth() / 2;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2;
	LoadTExture();
	_openExitDialog = false;
	CreateButton(&_yesButton, Vector2(_basePos.x - _space / 2 - _yesTexture.GetWidth(), _basePos.y), &_yesTexture);
	CreateButton(&_noButton, Vector2(_basePos.x + _space / 2, _basePos.y), &_noTexture);
}

void ExitGame::LoadTExture() {
	_yesTexture.Load("‚Í‚¢.png");
	_noTexture.Load("‚¢‚¢‚¦.png");
}



void ExitGame::Update() {
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE)) {
		_openExitDialog = true;
	}
}

void ExitGame::CreateButton(Button* button, Vector2 pos, CTexture* texture) {
	button->SetStatu(pos, texture);
}
void ExitGame::Push(Vector2 mousePos) {
	if (!_openExitDialog)return;

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) {
		if (_yesButton.CheckOnButton(mousePos)) {
			PostQuitMessage(0);
		}

		if (_noButton.CheckOnButton(mousePos)) {
			_openExitDialog = false;
		}
	}

}

void ExitGame::Render() {
	if (_openExitDialog) {
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
		_yesButton.Render();
		_noButton.Render();
	}
}

void ExitGame::Release() {
	_yesTexture.Release();
	_noTexture.Release();
}