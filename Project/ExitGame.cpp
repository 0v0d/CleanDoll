#include "ExitGame.h"

void ExitGame::Initialize() {

	LoadTexture();
	LaodSound();

	Vector2 _basePos=Vector2(g_pGraphics->GetTargetWidth() / 2, g_pGraphics->GetTargetHeight() / 2);
	const float	 spaceX = 100;
	const int spaceY = 60;

	CreateButton(&_yesButton, Vector2(_basePos.x - spaceX / 2 - _yesTexture.GetWidth() / 2, _basePos.y + spaceY), &_yesTexture, [&] {PostQuitMessage(0); });
	CreateButton(&_noButton, Vector2(_basePos.x + spaceX / 2 + _noTexture.GetWidth() / 2, _basePos.y + spaceY), &_noTexture, [&] {	
		SetMousePos(Vector2(0, 0));
		_openExitDialog = false;
		});

	_openExitDialog = false;
}

void ExitGame::LoadTexture() {
	_yesTexture.Load("ÇÕÇ¢.png");
	_noTexture.Load("Ç¢Ç¢Ç¶.png");
	_exitDialogTexture.Load("ÉQÅ[ÉÄÇèIóπÇµÇ‹Ç∑Ç©ÅH.png");
}

void ExitGame::LaodSound() {
	_buttonSe.Load("BottanClick.mp3");
}

void ExitGame::CreateButton(Button* button, Vector2 pos, CTexture* texture, std::function<void()> callMethod) {
	button->SetTexture(texture);
	button->SetPosition(pos);

	button->SetStatu(false, true, callMethod);
	button->SetSeSound(&_buttonSe);
}


void ExitGame::Update() {

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
}

void ExitGame::Render() {
	if (_openExitDialog) {
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(230, 0, 0, 0));
		_exitDialogTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - _exitDialogTexture.GetWidth() / 2 * _backScale,
			g_pGraphics->GetTargetHeight() / 2 - _exitDialogTexture.GetHeight() / 2 * _backScale, _backScale);
		_yesButton.Render();
		_noButton.Render();
	}
}

void ExitGame::Release() {
	_yesTexture.Release();
	_noTexture.Release();
	_exitDialogTexture.Release();
	_buttonSe.Release();
}