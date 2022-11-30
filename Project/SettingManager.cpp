#include "SettingManager.h"

void SettingManager::Initialize()
{
	_setUpSetting.SetOpenMenu(&_openMenu);
	_setUpSetting.Initialize();
	_openSettingButton.Initialize();
	_openMenu = false;
	_menuTexture.Load("ƒƒjƒ…[@UI.png");
}

void SettingManager::Update()
{
	if (_openMenu)
	{
		_setUpSetting.Update();
	}
}

void SettingManager::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	_setUpSetting.SetMousePos(mousePos);
}

void SettingManager::Push() {
	if (!_openMenu)
	{
		if (_openSettingButton.CheckPushButton(_mousePos))
		{
			_openMenu = true;
			_setUpSetting.DetermineBackScene();
		}
	}
	else
	{
		_setUpSetting.Push();
	}
}

void SettingManager::Pull() {
	if (_openMenu){
		_setUpSetting.Pull();
	}
}

void SettingManager::Render()
{
	_openSettingButton.Render();
	if (_openMenu)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
		_setUpSetting.Render();
		_menuTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _menuTexture.GetWidth() / 2, 50);
	}
}

void SettingManager::Release()
{
	_setUpSetting.Release();
	_openSettingButton.Release();
	_menuTexture.Release();
}