#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void GameClear::Initialize()
{
	LoadTexture();
	_gameClearAnim.Initialize();
	_clearBackGround.Initialize();

	_nextButtonPos = Vector2(400, 300);
	_stageSelectButtonPos = Vector2(400, 500);
	_retryButtonPos = Vector2(400, 700);

	_nextStageButton.SetStatu(_nextButtonPos, &_nextStageTexture);
	_stageSelectButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_retryButton.SetStatu(_retryButtonPos, &_retryTexture);
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
	_clearBackGround.Render();
	_gameClearAnim.Render();
	if (_gameClearAnim.IsEndeMotion())
	{
		_nextStageTexture.Render(_nextButtonPos.x, _nextButtonPos.y);
		_stageSelectTexture.Render(_stageSelectButtonPos.x, _stageSelectButtonPos.y);
		_retryTexture.Render(_retryButtonPos.x, _retryButtonPos.y);
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
