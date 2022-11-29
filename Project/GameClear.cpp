#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void GameClear::Initialize()
{
	LoadTexture();
	_firstButtonPos = Vector2(400, 300);
	_secondButtonPos = Vector2(400, 500);
	_thirdButtonPos = Vector2(400, 700);

	_nextStageButton.SetStatu(_firstButtonPos, &_nextStageTexture);
	_stageSelectButton.SetStatu(_secondButtonPos, &_stageSelectTexture);
	_retryButton.SetStatu(_thirdButtonPos, &_retryTexture);
}

void GameClear::LoadTexture()
{
	_nextStageTexture.Load("ステージ選択へ.png");
	_stageSelectTexture.Load("ステージ選択へ.png");
	_retryTexture.Load("ステージ選択へ.png");
}

void GameClear::ReLoad()
{

}

void GameClear::Update()
{

}

void GameClear::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
}

void GameClear::Push() {
	if (_nextStageButton.CheckOnButton(_mousePos))
	{
		//次のステージへ
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StartNextStage();
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}

	if (_stageSelectButton.CheckOnButton(_mousePos))
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}

	if (_retryButton.CheckOnButton(_mousePos))
	{
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}
}

void GameClear::Pull() {

}

void GameClear::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_nextStageButton.Render();
	_stageSelectButton.Render();
	_retryButton.Render();
}

void GameClear::Release()
{
	_nextStageTexture.Release();
	_stageSelectTexture.Release();
	_retryTexture.Release();
}
