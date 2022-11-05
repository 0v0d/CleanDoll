#include "OpenSetting.h"

void OpenSetting::Initialize()
{

	_openButtonTexture.Load("ê›íËÉçÉS.png");
	_openSettingPosition = Vector2(1920-500, 50);
	_openButton.SetStatu(_openSettingPosition, &_openButtonTexture);
}

void OpenSetting::Render()
{
	_openButton.Render();
}

void OpenSetting::Release()
{
	_openButtonTexture.Release();
}