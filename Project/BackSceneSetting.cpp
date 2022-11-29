#include "BackSceneSetting.h"

void BackSceneSetting::Initialize()
{
	_backTexture.Load("‚Í‚¢.png");
	_closeTexture.Load("‚¢‚¢‚¦.png");

	CreateButton(&_backButton, Vector2(g_pGraphics->GetTargetWidth() / 2 - _backTexture.GetWidth()-30, 450), &_backTexture);
	CreateButton(&_closeButton, Vector2(g_pGraphics->GetTargetWidth() / 2 + 20, 450), &_closeTexture);
	
}

void BackSceneSetting::Update(){

}

void BackSceneSetting::CreateButton(Button* button, Vector2 pos, CTexture* texture) {
	button->SetStatu(pos, texture);
}

void BackSceneSetting::Push(Vector2 mousePos)
{
	PushButton(mousePos);
}

void BackSceneSetting::Pull(Vector2 mousePos)
{

}

void BackSceneSetting::SetBackScene(SCENE_TYPE backScene) {
	_backScene = backScene;
}

void BackSceneSetting::PushButton(Vector2 mousePos)
{
	if(_closeButton.CheckOnButton(mousePos))
	{
		*_openBackSceneSetting = false;
		return;
	}
	if (_backButton.CheckOnButton(mousePos)) {
		SceneManager::Instance().ChangeScene(_backScene);
		*_openMenu = false;
		*_openBackSceneSetting = false;

		return;
	}
}

void BackSceneSetting::Render()
{
	_backButton.Render();
	_closeButton.Render();
}

void BackSceneSetting::Release()
{
	_backTexture.Release();
	_closeTexture.Release();
}