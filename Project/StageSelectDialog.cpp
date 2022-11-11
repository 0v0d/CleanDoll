#include "StageSelectDialog.h"

void StageSelectDialog::Initialize() {
	_Pos.x = g_pGraphics->GetTargetWidth()/2;
	_Pos.y = g_pGraphics->GetTargetHeight() / 2;
	_YesTexture.Load("ŠÛ.png");
	_NoTexture.Load("ƒoƒc.png");
	_OpenStaSeleDia = false;
}

void StageSelectDialog::SetYesButton() {
	_YesButtonPos = Vector2(_Pos.x-_YesTexture.GetWidth()-10,_Pos.y);
	_YesButton.SetStatu(_YesButtonPos, &_YesTexture);
}

void StageSelectDialog::SetNoButton() {
	_NoButtonPos = Vector2(_Pos.x + _NoTexture.GetWidth() + 10, _Pos.y);
	_NoButton.SetStatu(_NoButtonPos, &_NoTexture);
}

void StageSelectDialog::Render() {
	if (_OpenStaSeleDia) {
		_YesButton.Render();
		_NoButton.Render();
	}
}

void StageSelectDialog::Release() {
	_YesTexture.Release();
	_NoTexture.Release();
}