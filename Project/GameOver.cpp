#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	LoadTexture();
	_firstButtonPos = Vector2(400, 300);
	_secondButtonPos = Vector2(400, 500);
	_retryButton.SetStatu(_firstButtonPos, &_retryTexture);
	_stageSelectButton.SetStatu(_secondButtonPos, &_stageSelectTexture);
}

void GameOver::LoadTexture()
{
	_retryTexture.Load("�X�e�[�W�I����.png");
	_stageSelectTexture.Load("�X�e�[�W�I����.png");
}

void GameOver::ReLoad()
{

}

void GameOver::Update()
{

}

void GameOver::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
}

void GameOver::Push() {
	if (_retryButton.CheckOnButton(_mousePos))
	{
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}

	if (_stageSelectButton.CheckOnButton(_mousePos))
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void GameOver::Pull() {

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