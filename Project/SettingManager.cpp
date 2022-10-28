#include "SettingManager.h"

void SettingManager::Initialize() {

	_setUpSetting.Initialize();
	_openSettingButton.Initialize();
}

void SettingManager::Update() {

}

void SettingManager::Push(Vector2 mousePos) {
	if (!_openMenu) {
		if (_openSettingButton.CheckPushButton(mousePos)) _openMenu = true;
	}
	else {
		_setUpSetting.Push(mousePos);
	}
}

void SettingManager::Pull(Vector2 mousePos) {

}

void SettingManager::Render() {
	if (_openMenu) _setUpSetting.Render();
	else _openSettingButton.Render();
}

void SettingManager::Release() {

	_setUpSetting.Release();
	_openSettingButton.Release();
}