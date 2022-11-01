#include "Menu.h"
#include "SceneManager.h"

void Menu::Initialize()
{

	_inputMenu.SetSettingManager(&_settingManager);
	_settingManager.Initialize();
}

void Menu::Update()
{
	_inputMenu.Update();
	_settingManager.Update();
}

void Menu::Render()
{
	_settingManager.Render();
}

void Menu::Release()
{
	_settingManager.Release();
}