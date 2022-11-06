#include "SettingManager.h"

void SettingManager::Initialize()
{
	_setUpSetting.SetOpenMenu(&_openMenu);
	_setUpSetting.Initialize();
	_openSettingButton.Initialize();
	_openMenu = false;
	_menuTexture.Load("ƒƒjƒ…[@UI.png");
	_menuBackTexture.Load("menu_back.png");
}

void SettingManager::Update()
{
	if (_openMenu)
	{
		_setUpSetting.Update();
	}
}

void SettingManager::Push(Vector2 mousePos)
{
	if (!_openMenu) 
	{
		if (_openSettingButton.CheckPushButton(mousePos))
		{
			_openMenu = true;
		}
	}
	else
	{
		_setUpSetting.Push(mousePos);
	}
}

void SettingManager::Pull(Vector2 mousePos)
{
	if (!_openMenu)
	{
		if (_openSettingButton.CheckPushButton(mousePos))
		{
			_openMenu = true;
		}
	}
	else 
	{
		_setUpSetting.Pull(mousePos);
	}
}

void SettingManager::Render()
{
	if (_openMenu)
	{
		_menuBackTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _menuBackTexture.GetWidth() / 2, 30);
		_setUpSetting.Render();
		_menuTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _menuTexture.GetWidth() / 2, 50);
	}
	_openSettingButton.Render();
}

void SettingManager::Release()
{
	_setUpSetting.Release();
	_openSettingButton.Release();
	_menuTexture.Release();
	_menuBackTexture.Release();
}