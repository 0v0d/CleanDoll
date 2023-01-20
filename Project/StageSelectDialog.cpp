#include "StageSelectDialog.h"

void StageSelectDialog::Initialize() {
	_basePos.x = g_pGraphics->GetTargetWidth()/2;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2;
	const float spaceX = 100;
	const int spaceY = 60;
	LoadTexture();
	LaodSound();
	CreateButton(&_yesButton, Vector2(_basePos.x - spaceX / 2 - _yesTexture.GetWidth() / 2, _basePos.y + spaceY), &_yesTexture, [&]() {_loadStageMethod(_pickStageNumber); });
	CreateButton(&_noButton, Vector2(_basePos.x + spaceX / 2 + _noTexture.GetWidth() / 2, _basePos.y + spaceY), &_noTexture, [&]() {
		_openStaSeleDialog = false;
		_clickCount = 0;
		_pickStageNumber = -1;
		});
}

void StageSelectDialog::ReLoad() {
	_openStaSeleDialog = false;
	_clickCount = 0;
	_pickStageNumber = -1;
}

void StageSelectDialog::LoadTexture() {
	_yesTexture.Load("はい.png");
	_noTexture.Load("いいえ.png");
	_backTexture.Load("ステージ選択後背景.png");

}

void StageSelectDialog::LaodSound() {
	_buttonSe.Load("BottanClick.mp3");
}

void StageSelectDialog::CreateButton(Button* button, Vector2 pos, CTexture* texture,std::function<void()> callMethod) {
	button->SetTexture(texture);
	button->SetPosition(pos);

	button->SetStatu(false,true,callMethod);
	button->SetSeSound(&_buttonSe);
}

void StageSelectDialog::Update() {

}

void StageSelectDialog::SetStageNumber(int stagenumber) {
	if (stagenumber == -1 || _openStaSeleDialog) return;

	switch (_clickCount) {
	case 0:
		_pickStageNumber = stagenumber;
		_clickCount = 1;
		break;

	case 1:
		if (_pickStageNumber == stagenumber) {
			_openStaSeleDialog = true;
		}
		else {
			_pickStageNumber = stagenumber;
		}
		break;
	}
}

void StageSelectDialog::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	_yesButton.SetMousePos(_mousePos);
	_noButton.SetMousePos(_mousePos);
}

void StageSelectDialog::Push(){
	if (!_openStaSeleDialog) return;

	_yesButton.Push();
	_noButton.Push();
}

void StageSelectDialog::Pull() {
	_yesButton.Pull();
	_noButton.Pull();
}

void StageSelectDialog::Render() {
	if (!_openStaSeleDialog) return;

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(200, 0, 0, 0));
	_backTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - _backTexture.GetWidth() / 2 * _backScale,
		g_pGraphics->GetTargetHeight() / 2 - _backTexture.GetHeight() / 2 * _backScale, _backScale);
	_yesButton.Render();
	_noButton.Render();
}

void StageSelectDialog::Release() {
	_yesTexture.Release();
	_noTexture.Release();
	_backTexture.Release();

	_buttonSe.Release();
}