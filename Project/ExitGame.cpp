#include "ExitGame.h"


void ExitGame::Initialize() {
	Vector2 _basePos;
	_basePos.x = g_pGraphics->GetTargetWidth() / 2;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2;
	LoadTexture();
	CreateButton(&_yesButton, Vector2(_basePos.x - _space / 2 - _yesTexture.GetWidth() / 2, _basePos.y), &_yesTexture);
	CreateButton(&_noButton, Vector2(_basePos.x + _space / 2 + _noTexture.GetWidth() / 2, _basePos.y), &_noTexture);

	_openExitDialog = false;
}

void ExitGame::LoadTexture() {
	_yesTexture.Load("はい.png");
	_noTexture.Load("いいえ.png");
}


void ExitGame::Update() {

}

void ExitGame::CreateButton(Button* button, Vector2 pos, CTexture* texture) {
	button->SetTexture(texture);
	button->SetPosition(pos);
}

void ExitGame::SetMousePos(Vector2 mousePos) {
	if (!_openExitDialog)return;

	_yesButton.SetMousePos(mousePos);
	_noButton.SetMousePos(mousePos);
}

void ExitGame::Push() {
	if (!_openExitDialog)return;

	_yesButton.Push();
	_noButton.Push();
}

void ExitGame::Pull() {
	if (!_openExitDialog)return;

	_yesButton.Pull();
	_noButton.Pull();

	if (_yesButton.IsPullButton()) {
		PostQuitMessage(0);
	}
	if (_noButton.IsPullButton()) {
		_openExitDialog = false;
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