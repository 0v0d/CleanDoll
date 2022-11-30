#include "Menu.h"
#include "SceneManager.h"

void Menu::Initialize()
{
	_settingManager.Initialize();
}

void Menu::Update()
{
	_settingManager.Update();
}

void Menu::SetMousePos(Vector2 mousePos) {
	_settingManager.SetMousePos(mousePos);
}

void Menu::Push() {
	_settingManager.Push();
}

void Menu::Pull() {
	_settingManager.Pull();
}

void Menu::Render()
{
	_settingManager.Render();
}

void Menu::Release()
{
	_settingManager.Release();
}