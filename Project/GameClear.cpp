#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void GameClear::Initialize()
{
	LoadTexture();
	_gameClearAnim.Initialize();
	_clearBackGround.Initialize();

	_nextButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2, 400);
	_stageSelectButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2, 600);
	_retryButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2, 800);

	_nextStageButton.SetTexture(&_nextStageTexture);
	_nextStageButton.SetPosition(_nextButtonPos);

	_stageSelectButton.SetTexture(&_stageSelectTexture);
	_stageSelectButton.SetPosition(_stageSelectButtonPos);

	_retryButton.SetTexture(&_retryTexture);
	_retryButton.SetPosition(_retryButtonPos);
}

void GameClear::LoadTexture()
{
	_nextStageTexture.Load("ステージ選択へ.png");
	_stageSelectTexture.Load("ステージ選択へ.png");
	_retryTexture.Load("ステージ選択へ.png");
}

void GameClear::ReLoad(){
	_gameClearAnim.ReLoad();
	_clearBackGround.ReLoad();
}

void GameClear::Update()
{
	UpdateAnimation();
}

void GameClear::UpdateAnimation() {
	if (!_clearBackGround.IsFixedScale())
	{
		_clearBackGround.Update();
	}
	else
	{
		_gameClearAnim.Update();
	}
}

void GameClear::SetMousePos(Vector2 mousePos) {
	_nextStageButton.SetMousePos(mousePos);
	_stageSelectButton.SetMousePos(mousePos);
	_retryButton.SetMousePos(mousePos);
}

void GameClear::Push() {

	_nextStageButton.Push();
	_stageSelectButton.Push();
	_retryButton.Push();
}

void GameClear::Pull() {
	_nextStageButton.Pull();
	_stageSelectButton.Pull();
	_retryButton.Pull();

	if (_nextStageButton.IsPullButton()) {
		//次のステージへ
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StartNextStage();
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}
	if (_stageSelectButton.IsPullButton()) {
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
	if (_retryButton.IsPullButton()) {
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}
}

void GameClear::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_clearBackGround.Render();
	_gameClearAnim.Render();
	if (_gameClearAnim.IsEndeMotion())
	{
		_nextStageButton.Render();
		_stageSelectButton.Render();
		_retryButton.Render();
	}
}

void GameClear::Release()
{
	_gameClearAnim.Release();
	_clearBackGround.Release();	
	_backStageClearTexture.Release();
	_nextStageTexture.Release();
	_stageSelectTexture.Release();
	_retryTexture.Release();
}
