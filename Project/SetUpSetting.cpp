#include "SetUpSetting.h"
#include	"AudioSetting.h"
#include	"BackSceneSetting.h"
#include "SceneManager.h"

void SetUpSetting::Initialize()
{
	LoadTexture();

	_audioButton.SetStatu(Vector2(g_pGraphics->GetTargetWidth()/2 - _audioButtonTexure.GetWidth()/2, 250), &_audioButtonTexure);
	_closeMenuButton.SetStatu(Vector2(g_pGraphics->GetTargetWidth() / 2 - _closeMenuTexture.GetWidth() / 2, 650), &_closeMenuTexture);

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

void SetUpSetting::Push(Vector2 mousePos)
{
	if (_openSetting)
	{
		_currentSetting->Push(mousePos);
	}
	else 
	{
		if (_closeMenuButton.CheckOnButton(mousePos))
		{
			*_openMenu = false;
			return;
		}

		for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++)
		{
			if (itr->first->CheckOnButton(mousePos))
			{
				_openSetting = true;
				_currentSetting = itr->second;
				break;
			}
		}
	}
}

void SetUpSetting::Pull(Vector2 mousePos)
{
	if (_openSetting)
	{
		_currentSetting->Pull(mousePos);
	}
}

void SetUpSetting::DetermineBackScene() {
	SCENE_TYPE currentSceneType = SceneManager::Instance().GetCurrentSceneType();
	SCENE_TYPE backSceneType = SCENE_TYPE::TITLE;

	switch (currentSceneType) {
	case  SCENE_TYPE::STAGESELECT:
		backSceneType = SCENE_TYPE::TITLE;
		_backSceneButton.SetStatu(Vector2(g_pGraphics->GetTargetWidth() / 2 - _backTitleSceneTexture.GetWidth() / 2, 450), &_backTitleSceneTexture);
		break;

	case  SCENE_TYPE::GAME:
		backSceneType = SCENE_TYPE::STAGESELECT;
		_backSceneButton.SetStatu(Vector2(g_pGraphics->GetTargetWidth() / 2 - _backSelectSceneTexture.GetWidth() / 2, 450), &_backSelectSceneTexture);
		break;
	}

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