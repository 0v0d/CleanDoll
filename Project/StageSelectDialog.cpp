#include "StageSelectDialog.h"

void StageSelectDialog::Initialize() {
	_Pos.x = g_pGraphics->GetTargetWidth()/2;
	_Pos.y = g_pGraphics->GetTargetHeight() / 3;
	_YesTexture.Load("ŠÛ.png");
	_NoTexture.Load("ƒoƒc.png");
	_OpenStaSeleDia = false;
	SetYesButton();
	SetNoButton();
	_clickCount = 0;
	_mPosX = 0;
	_mPosY = 0;
}

void StageSelectDialog::SetYesButton() {
	_YesButtonPos = Vector2(_Pos.x-_YesTexture.GetWidth()-10,_Pos.y);
	_YesButton.SetStatu(_YesButtonPos, &_YesTexture);
}

void StageSelectDialog::SetNoButton() {
	_NoButtonPos = Vector2(_Pos.x , _Pos.y);
	_NoButton.SetStatu(_NoButtonPos, &_NoTexture);
}

void StageSelectDialog::Update() {

}

void StageSelectDialog:: SetStageNumber(int stagenumber) {
	if (stagenumber ==-1) return;
	if (_clickCount == 0) {
		_stagenumber = stagenumber;
		_clickCount = 1;
	}
	else if (_clickCount == 1 && _stagenumber == stagenumber) {
		_clickCount += 1;
	}
	else if (_clickCount == 1 && _stagenumber != stagenumber) {
		_clickCount = 0;
	}

	if (_clickCount >= 2) {
		_OpenStaSeleDia = true;
	}
}


void StageSelectDialog ::CloseDialog (Vector2 mousePos) {
	if (_OpenStaSeleDia) {
		if (CheckNoButton(mousePos)) {
			_OpenStaSeleDia = false;
			_clickCount = 0;
		}
	}
}
void StageSelectDialog::Push(Vector2 mousePos){
	if (_OpenStaSeleDia) {
		CheckYesButton(mousePos);
	}
}

void StageSelectDialog::Render() {
	if (_OpenStaSeleDia) {
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
		_YesButton.Render();
		_NoButton.Render();
	}
}

void StageSelectDialog::Release() {
	_YesTexture.Release();
	_NoTexture.Release();
}