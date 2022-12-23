#include "DollMoveSetting.h"

void DollMoveSetting::Initialize()
{
	LoadTexture();
	CalcuScale();

	

	


	_closeButton.SetTexture(&_closeButtonTexture);
	_closeButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 870));

	

	
}

void DollMoveSetting::LoadTexture() {

	_closeButtonTexture.Load("戻る　テキスト.png");
	
}
void DollMoveSetting::Update()
{
	
}

void DollMoveSetting::CalcuScale() {
	
}



void DollMoveSetting::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	_closeButton.SetMousePos(mousePos);
}

void DollMoveSetting::Push()
{
	
	_closeButton.Push();
}

void DollMoveSetting::Pull()
{
	

	_closeButton.Pull();
	if (_closeButton.IsPullButton()) {
		*_openAudioSetting = false;
	}
}

void DollMoveSetting::Render()
{
	
	_closeButton.Render();

	
	
}

void DollMoveSetting::Release()
{
	_closeButtonTexture.Release();
	
}