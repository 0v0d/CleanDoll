#include "SetUpSetting.h"
#include	"AudioSetting.h"
#include	"BackSceneSetting.h"
#include "SceneManager.h"

void SetUpSetting::Initialize()
{
	LoadTexture();

	_audioButton.SetTexture(&_audioButtonTexure);
	_audioButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 300));

	_backSceneButton.SetTexture(&_backTitleSceneTexture);
	_backSceneButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 500));


	_closeMenuButton.SetTexture(&_closeMenuTexture);
	_closeMenuButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 700));

	_buttonArray[&_audioButton] = new AudioSetting();
	_buttonArray[&_backSceneButton] = new BackSceneSetting();

	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++)
	{
		itr->second->Initialize();
		itr->second->SetOpenSetting(&_openSetting);
	}

	dynamic_cast<BackSceneSetting*>(_buttonArray[&_backSceneButton])->SetOpenMenu(_openMenu);
	_openSetting = false;
}

void SetUpSetting::LoadTexture() {
	_audioButtonTexure.Load("サウンド設定　.png");
	_backTitleSceneTexture.Load("clictostart.png");
	_backSelectSceneTexture.Load("ステージ選択へ.png");
	_closeMenuTexture.Load("閉じる.png");
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
		CheckPullButton();
	}
}

void SetUpSetting::CheckPullButton() {
	if (_closeMenuButton.IsPullButton()) {
		*_openMenu = false;
	}

	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++)
	{
		if (itr->first->IsPullButton())
		{
			_openSetting = true;
			_currentSetting = itr->second;
			break;
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
	_backSceneButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 500));

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
	_backTitleSceneTexture.Release();
	_backSelectSceneTexture.Release();
	_closeMenuTexture.Release();
	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
		itr->second->Release();
	}
}