#include "SetUpSetting.h"

void SetUpSetting::Initialize() {

	_audioSetting.SetOpenSetting(&_openSetting);
	_audioSetting.Initialize();
}

void SetUpSetting::Update() {
	if(_openSetting)_audioSetting.Update();
}

void SetUpSetting::Push(Vector2 mousePos) {
	_audioSetting.Push(mousePos);
}

void SetUpSetting::Render() {
	if (_openSetting)_audioSetting.Render();
}

void SetUpSetting::Release() {
	_audioSetting.Release();
}