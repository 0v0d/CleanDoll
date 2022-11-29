#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"


void GameClear::TextureLoad()
{
	_nextStageTexture.Load("ステージ選択へ.png");
	_stageSelectTexture.Load("ステージ選択へ.png");
	_retryTexture.Load("ステージ選択へ.png");
}



void GameClear::Initialize()
{
	TextureLoad();
	_gameClearAnim.Initialize();
	_clearBackGround.Initialize();

	_nextButtonPos = Vector2(400, 300);
	_stageSelectButtonPos = Vector2(400, 500);
	_retryButtonPos = Vector2(400, 700);
	Vector2 _size = Vector2(300, 120);
	

	_nextStageButton.SetStatu(_nextButtonPos, &_nextStageTexture);
	_stageSelectButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_retryButton.SetStatu(_retryButtonPos, &_retryTexture);
	_goal = false;
	_remove = false;
	_mousePos = Vector2(0, 0);
}

void GameClear::Reload()
{
	_gameClearAnim.Initialize();
	_clearBackGround.Initialize();
	_goal = false;
	_remove = false;
}

void GameClear::Update()
{
	if (IsGoal())
	{
		
		g_pInput->GetMousePos(_mousePos);

		if (!_clearBackGround.IsFixedScale())
		{
			_clearBackGround.Update();
		}
		else
		{
			_gameClearAnim.Update();
		}
	

		if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
		{
			if (_nextStageButton.CheckOnButton(_mousePos))
			{
				//次のステージへ
				_remove = true;
				dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StartNextStage();
			}			
			if (_stageSelectButton.CheckOnButton(_mousePos))
			{
				_remove = true;
				SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
			}

			if (_retryButton.CheckOnButton(_mousePos))
			{
				SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
			}
			
			
		}
	}
}


void GameClear::Render()
{
	if (IsGoal())
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
		_clearBackGround.ScaleRender();
		_gameClearAnim.Render();
		if (_gameClearAnim.IsEndeMotion())
		{
			_nextStageTexture.Render(_nextButtonPos.x, _nextButtonPos.y);
			_stageSelectTexture.Render(_stageSelectButtonPos.x, _stageSelectButtonPos.y);
			_retryTexture.Render(_retryButtonPos.x, _retryButtonPos.y);
		}
		
	}
}

void GameClear::Release()
{
	_gameClearAnim.Release();
	_clearBackGround.Release();
	_nextStageTexture.Release();
	_stageSelectTexture.Release();
	_retryTexture.Release();
	_backStageClearTexture.Release();
}
