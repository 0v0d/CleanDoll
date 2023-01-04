#include "BackSceneSetting.h"

void BackSceneSetting::Initialize()
{
	Vector2 _basePos;
	_basePos.x = g_pGraphics->GetTargetWidth() / 2;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2;
	const float _space = 100;
	_backTexture.Load("‚Í‚¢.png");
	_closeTexture.Load("‚¢‚¢‚¦.png");
	_buttonSe.Load("BottanClick.mp3");

	CreateButton(&_backButton, Vector2(g_pGraphics->GetTargetWidth() / 2 - _backTexture.GetWidth() - 30, 450), &_backTexture, [&]() {
		SceneManager::Instance().ChangeScene(_backScene);
		*_openMenu = false;
		*_openBackSceneSetting = false;
		});

	CreateButton(&_closeButton, Vector2(g_pGraphics->GetTargetWidth() / 2 + 20, 450), &_closeTexture, [&]() {
		*_openBackSceneSetting = false;
		});
}

void BackSceneSetting::CreateButton(Button* button, Vector2 pos, CTexture* texture, std::function<void()> callMethod) {
	button->SetTexture(texture);
	button->SetPosition(pos);

	button->SetSeSound(&_buttonSe);
	button->SetStatu(false, true, callMethod);
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
}

void BackSceneSetting::SetBackScene(SCENE_TYPE backScene) {
	_backScene = backScene;
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
	_buttonSe.Release();
}