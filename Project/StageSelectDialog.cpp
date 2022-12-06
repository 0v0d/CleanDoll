#include "StageSelectDialog.h"

void StageSelectDialog::Initialize() {
	_basePos.x = g_pGraphics->GetTargetWidth()/2;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2;

	LoadTexture();

	CreateButton(&_yesButton, Vector2(_basePos.x - _space / 2 - _yesTexture.GetWidth(), _basePos.y), &_yesTexture);
	CreateButton(&_noButton, Vector2(_basePos.x + _space / 2, _basePos.y), &_noTexture);
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

void StageSelectDialog::CreateButton(Button* button, Vector2 pos, CTexture* texture) {
	button->SetTexture(texture);
	button->SetPosition(pos);
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

	if (_yesButton.IsPullButton()) {
		_loadStageMethod(_pickStageNumber);
	}

	if (_noButton.IsPullButton()) {
		_openStaSeleDialog = false;
		_clickCount = 0;
		_pickStageNumber = -1;
	}
}

void StageSelectDialog::Render() {
	if (!_openStaSeleDialog) return;

	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_backTexture.Render(0, 0);
	_yesButton.Render();
	_noButton.Render();
}

void StageSelectDialog::Release() {
	_yesTexture.Release();
	_noTexture.Release();
	_backTexture.Release();
}