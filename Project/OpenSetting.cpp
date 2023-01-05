#include "OpenSetting.h"

void OpenSetting::Initialize()
{
	_openButtonTexture.Load("Ý’èƒƒS.png");
	_openSettingPosition = Vector2(g_pGraphics->GetTargetWidth() - 150, 100);
	_openButton.SetTexture(&_openButtonTexture);
	_openButton.SetPosition(_openSettingPosition);
}

void OpenSetting::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	_openButton.SetMousePos(_mousePos);
}

void OpenSetting::Push() {
	_openButton.Push();
}

void OpenSetting::Pull() {
	_openButton.Pull();
}

void OpenSetting::Render()
{
	_openButton.Render();

}

void OpenSetting::Release()
{
	_openButtonTexture.Release();
}