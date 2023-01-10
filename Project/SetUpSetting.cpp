#include "SetUpSetting.h"
#include "AudioSetting.h"
#include "BackSceneSetting.h"
#include "DollMoveSetting.h"
#include "SceneManager.h"

void SetUpSetting::Initialize()
{
	LoadTexture();
	_audioButton.SetTexture(&_audioButtonTexure);
	_audioButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 300));

	_dollButton.SetTexture(&_dollButtonTexture);
	_dollButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 500));

	_backSceneButton.SetTexture(&_backTitleSceneTexture);
	_backSceneButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 700));

	_closeMenuButton.SetTexture(&_closeMenuTexture);
	_closeMenuButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 900));


	_buttonArray[&_audioButton] = new AudioSetting();
	_buttonArray[&_dollButton] = new DollMoveSetting();
	_buttonArray[&_backSceneButton] = new BackSceneSetting();

	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++)
	{
		itr->second->Initialize();
		itr->second->SetOpenSetting(&_openSetting);
	}

	CreateButton();

	dynamic_cast<BackSceneSetting*>(_buttonArray[&_backSceneButton])->SetOpenMenu(_openMenu);
	_openSetting = false;
}

void SetUpSetting::LoadTexture() {
	_audioButtonTexure.Load("サウンド設定　.png");
	_dollButtonTexture.Load("ゲームをやめる.png");
	_backTitleSceneTexture.Load("clictostart.png");
	_backSelectSceneTexture.Load("ステージ選択へ.png");
	_closeMenuTexture.Load("閉じる.png");

	_buttonSe.Load("ClicktoStart.mp3");
}

void SetUpSetting::CreateButton() {
	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
		itr->first->SetSeSound(&_buttonSe);
	}

	_audioButton.SetStatu(false, true, [&]() {
		_openSetting = true;
		_currentSetting = _buttonArray[&_audioButton];
		});

	_dollButton.SetStatu(false,true, [&]() {
		_openSetting = true;
		_currentSetting = _buttonArray[&_dollButton];
		});

	_backSceneButton.SetStatu(false, true, [&]() {
		_openSetting = true;
		_currentSetting = _buttonArray[&_backSceneButton];
		});

	_closeMenuButton.SetSeSound(&_buttonSe);
	_closeMenuButton.SetStatu(false, true, [&]() {
		*_openMenu = false;
		SetMousePos(Vector2(0, 0));
		});
}

void SetUpSetting::Update()
{
	if (_openSetting)
	{
		_currentSetting->Update();
	}
}

void SetUpSetting::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;

	if (_openSetting) {
		_currentSetting->SetMousePos(mousePos);
		return;
	}

	_closeMenuButton.SetMousePos(mousePos);
	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
		itr->first->SetMousePos(mousePos);
	}
}

void SetUpSetting::Push()
{
	if (_openSetting){
		_currentSetting->Push();
		return;
	}

	_closeMenuButton.Push();
	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
		itr->first->Push();
	}
}

void SetUpSetting::Pull()
{
	if (_openSetting) {
		_currentSetting->Pull();
	}
	else {
		_closeMenuButton.Pull();
		for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
			itr->first->Pull();
		}
	}
}

void SetUpSetting::DetermineBackScene() {
	SCENE_TYPE currentSceneType = SceneManager::Instance().GetCurrentSceneType();
	SCENE_TYPE backSceneType = SCENE_TYPE::TITLE;

	switch (currentSceneType) {
	case  SCENE_TYPE::STAGESELECT:
		backSceneType = SCENE_TYPE::TITLE;
		_backSceneButton.SetTexture(&_backTitleSceneTexture);
		break;

	case  SCENE_TYPE::GAME:
		backSceneType = SCENE_TYPE::STAGESELECT;
		_backSceneButton.SetTexture(&_backSelectSceneTexture);
		break;
	}
	//_backSceneButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 500));

	dynamic_cast<BackSceneSetting*>(_buttonArray[&_backSceneButton])->SetBackScene(backSceneType);
}


void SetUpSetting::Render()
{
	if (_openSetting)
	{
		_currentSetting->Render();
	}
	else
	{
		for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++)
		{
			itr->first->Render();
		}
		_closeMenuButton.Render();
	}
}

void SetUpSetting::Release()
{
	_audioButtonTexure.Release();
	_dollButtonTexture.Release();
	_backTitleSceneTexture.Release();
	_backSelectSceneTexture.Release();
	_closeMenuTexture.Release();
	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
		itr->second->Release();
		delete itr->second;
	}

	_buttonSe.Release();
}