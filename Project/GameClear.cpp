#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void GameClear::Initialize()
{
	LoadTexture();
	_gameClearAnim.Initialize();
	_clearBackGround.Initialize();
	_clearDoll.Initialize();
	for (int i = 0; i < _menuValue; i++)
	{
		_endGameButton[i].Initialize();
	}

	_nextButtonPos = Vector2(500, 450);
	_stageSelectButtonPos = Vector2(500, 650);
	_retryButtonPos = Vector2(500, 850);
	Vector2 _size = Vector2(300, 120);

	_nextStageButton.SetStatu(_nextButtonPos, &_nextStageTexture);
	_stageSelectButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_retryButton.SetStatu(_retryButtonPos, &_retryTexture);
	_endGameButton[0].SetStatu(_nextButtonPos, &_nextStageTexture);
	_endGameButton[1].SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_endGameButton[2].SetStatu(_retryButtonPos, &_retryTexture);
}

void GameClear::LoadTexture()
{
	_nextStageTexture.Load("次のステージ.png");
	_stageSelectTexture.Load("ステージ選択に戻る.png");
	_retryTexture.Load("ステージをやり直す.png");
}

void GameClear::ReLoad(){
	_gameClearAnim.ReLoad();
	_clearBackGround.ReLoad();
	for (int i = 0; i < _menuValue; i++)
	{
		_endGameButton[i].Initialize();
	}
}

void GameClear::Update()
{
	UpdateAnimation();
}

void GameClear::UpdateAnimation() 
{
	if (!_clearBackGround.IsFixedScale())
	{
		_clearBackGround.Update();
	}
	else
	{
		_gameClearAnim.Update();
	}

	if (_gameClearAnim.IsEndeMotion())
	{
		_clearDoll.Update();
	}


	if (_gameClearAnim.IsEndeMotion())
	{

		for (int i = 0; i < _menuValue; i++) {
			_endGameButton[i].Update();
		}
	}

}

void GameClear::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
}

void GameClear::Push() {

	if (_endGameButton[2].IsEndAnimation())
	{
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
		
		_clearDoll.Render();
		for (int i = 0; i < _menuValue; i++) 
		{
			_endGameButton[i].Render();
		}
	
	}
}

void GameClear::Release()
{
	_gameClearAnim.Release();
	_clearBackGround.Release();	
	_clearDoll.Release();
	_backStageClearTexture.Release();
	_nextStageTexture.Release();
	_stageSelectTexture.Release();
	_retryTexture.Release();
	for (int i = 0; i < _menuValue; i++) {
		_endGameButton[i].Release();
	}
	_backStageClearTexture.Release();

	delete[] _endGameButton;
}
