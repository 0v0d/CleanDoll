#include "BackSceneSetting.h"

void BackSceneSetting::Initialize()
{
	Vector2 _basePos;
	_basePos.x = g_pGraphics->GetTargetWidth() / 2;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2;
	const float spaceX = 100;
	const float spaceY = 100;
	_backTexture.Load("はい.png");
	_closeTexture.Load("いいえ.png");
	_buttonSe.Load("BottanClick.mp3");
	_backTitleTextureDialog.Load("タイトルに戻りますか？.png");
	_backSelectSceneDialog.Load("ステージ選択に戻りますか？.png");

	CreateButton(&_backButton, Vector2(_basePos.x - spaceX / 2 - _backTexture.GetWidth() / 2, _basePos.y + spaceY), &_backTexture, [&]() {
		SceneManager::Instance().ChangeScene(_backScene);
	*_openMenu = false;
	*_openBackSceneSetting = false;
		});

	CreateButton(&_closeButton, Vector2(_basePos.x + spaceX / 2 + _closeTexture.GetWidth() / 2, _basePos.y + spaceY), &_closeTexture, [&]() {
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
	if (_Titledialog) {
		_backTitleTextureDialog.RenderScale(g_pGraphics->GetTargetWidth() / 2 - _backTitleTextureDialog.GetWidth() / 2 * _backScale,
			g_pGraphics->GetTargetHeight() / 2 - _backTitleTextureDialog.GetHeight() / 2 * _backScale, _backScale);
	}
	else if (_SelectSecnedialog) {
		_backSelectSceneDialog.RenderScale(g_pGraphics->GetTargetWidth() / 2 - _backSelectSceneDialog.GetWidth() / 2 * _backScale,
			g_pGraphics->GetTargetHeight() / 2 - _backSelectSceneDialog.GetHeight() / 2 * _backScale, _backScale);
	}

	_backButton.Render();
	_closeButton.Render();
}

void BackSceneSetting::Release()
{
	_backTitleTextureDialog.Release();
	_backSelectSceneDialog.Release();
	_backTexture.Release();
	_closeTexture.Release();
	_buttonSe.Release();
}