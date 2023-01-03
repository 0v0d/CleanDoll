#include "BackSceneSetting.h"

void BackSceneSetting::Initialize()
{
	Vector2 _basePos;
	_basePos.x = g_pGraphics->GetTargetWidth() / 2;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2;
	const float _space = 100;
	_backTexture.Load("‚Í‚¢.png");
	_closeTexture.Load("‚¢‚¢‚¦.png");

	CreateButton(&_backButton, Vector2(_basePos.x - _space / 2 - _backTexture.GetWidth() / 2, _basePos.y), &_backTexture);
	CreateButton(&_closeButton, Vector2(_basePos.x + _space / 2 + _closeTexture.GetWidth() / 2, _basePos.y), &_closeTexture);
}

void BackSceneSetting::CreateButton(Button* button, Vector2 pos, CTexture* texture) {
	button->SetTexture(texture);
	button->SetPosition(pos);
}

void BackSceneSetting::Update() {

}

void BackSceneSetting::SetMousePos(Vector2 mousePos) {
	_backButton.SetMousePos(mousePos);
	_closeButton.SetMousePos(mousePos);
}

void BackSceneSetting::Push()
{
	_backButton.Push();
	_closeButton.Push();
}

void BackSceneSetting::Pull()
{
	_backButton.Pull();
	_closeButton.Pull();

	CheckPullButtonCheck();
}

void BackSceneSetting::SetBackScene(SCENE_TYPE backScene) {
	_backScene = backScene;
}

void BackSceneSetting::CheckPullButtonCheck(){
	if (_closeButton.IsPullButton())
	{
		*_openBackSceneSetting = false;
		return;
	}
	if (_backButton.IsPullButton()) {
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