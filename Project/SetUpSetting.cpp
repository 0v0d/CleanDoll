#include "SetUpSetting.h"
#include	"AudioSetting.h"
#include	"BackSceneSetting.h"

void SetUpSetting::Initialize()
{
	_audioButtonTexure.Load("サウンド設定　.png");
	_backSceneTexture.Load("ステージ選択へ.png");
	_closeMenuTexture.Load("閉じる.png");
	_audioButton.SetStatu(Vector2(g_pGraphics->GetTargetWidth()/2 - _audioButtonTexure.GetWidth()/2, 250), &_audioButtonTexure);
	_backSceneButton.SetStatu(Vector2(g_pGraphics->GetTargetWidth() / 2 - _backSceneTexture.GetWidth()/2, 450), &_backSceneTexture);
	_closeMenuButton.SetStatu(Vector2(g_pGraphics->GetTargetWidth() / 2 - _closeMenuTexture.GetWidth() / 2, 650), &_closeMenuTexture);

	_buttonArray[&_audioButton] = new AudioSetting;
	_buttonArray[&_backSceneButton] = new BackSceneSetting;

	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++)
	{
		itr->second->Initialize();
		itr->second->SetOpenSetting(&_openSetting);
	}
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
	_backSceneTexture.Release();
	_closeMenuTexture.Release();
	for (auto itr = _buttonArray.begin(); itr != _buttonArray.end(); itr++) {
		itr->second->Release();
	}

}