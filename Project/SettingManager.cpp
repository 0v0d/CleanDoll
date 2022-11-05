#include "SettingManager.h"

void SettingManager::Initialize()
{
	_setUpSetting.SetOpenMenu(&_openMenu);

	_setUpSetting.Initialize();
	_openSettingButton.Initialize();

	_openMenu = false;
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
		_setUpSetting.Render();
	}
	else
	{
		_openSettingButton.Render();
	}
}

void SettingManager::Release()
{
	_setUpSetting.Release();
	_openSettingButton.Release();
}