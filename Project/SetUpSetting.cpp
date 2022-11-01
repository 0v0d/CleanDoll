#include "SetUpSetting.h"
#include	"AudioSetting.h"
#include	"BackSceneSetting.h"

void SetUpSetting::Initialize() {

	_audioButton.SetStatu(Vector2(700, 250), Vector2(100, 50));
	_backSceneButton.SetStatu(Vector2(700, 450), Vector2(100, 50));

	_buttonArray[&_audioButton] = new AudioSetting;
	_buttonArray[&_backSceneButton] = new BackSceneSetting;

	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
		itr->second->Initialize();
		itr->second->SetOpenSetting(&_openSetting);
	}

	_closeMenuButton = CRectangle(700, 700, 800, 750);
}

void SetUpSetting::Update() {
	if (_openSetting)_currentSetting->Update();
}

void SetUpSetting::Push(Vector2 mousePos) {
	if (_openSetting)_currentSetting->Push(mousePos);
	else {
		if (CheckPuchButton(mousePos, _closeMenuButton)) {
			*_openMenu = false;
			return;
		}

		for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
			if (itr->first->CheckPushButton(mousePos)) {

				_openSetting = true;
				_currentSetting = itr->second;
				break;
			}
		}
	}
}

void SetUpSetting::Render() {
	if (_openSetting)_currentSetting->Render();
	else {
		for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
			itr->first->Render();
		}
		CGraphicsUtilities::RenderFillRect(_closeMenuButton, MOF_COLOR_GREEN);
	}
}

void SetUpSetting::Release() {

}