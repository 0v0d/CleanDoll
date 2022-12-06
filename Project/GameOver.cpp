#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	LoadTexture();
	_firstButtonPos = Vector2(g_pGraphics->GetTargetWidth()/2, 400);
	_secondButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2, 600);

	_retryButton.SetTexture(&_retryTexture);
	_retryButton.SetPosition(_firstButtonPos);
	_stageSelectButton.SetTexture(&_stageSelectTexture);
	_stageSelectButton.SetPosition(_secondButtonPos);
}

void GameOver::LoadTexture()
{
	_retryTexture.Load("ステージ選択へ.png");
	_stageSelectTexture.Load("ステージ選択へ.png");
}

void GameOver::ReLoad()
{

}

void GameOver::Update()
{

}

void GameOver::SetMousePos(Vector2 mousePos) {
	_retryButton.SetMousePos(mousePos);
	_stageSelectButton.SetMousePos(mousePos);
}

void GameOver::Push() {
	_retryButton.Push();
	_stageSelectButton.Push();
}

void GameOver::Pull() {
	_retryButton.Pull();
	_stageSelectButton.Pull();

	if (_retryButton.IsPullButton()) {
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}
	if (_stageSelectButton.IsPullButton()) {
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void GameOver::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_retryButton.Render();
	_stageSelectButton.Render();
}

void GameOver::Release()
{
	_retryTexture.Release();
	_stageSelectTexture.Release();
}