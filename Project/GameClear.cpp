#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"


void GameClear::TextureLoad()
{
	_nextStageTexture.Load("ステージ選択へ.png");
	_stageSelectTexture.Load("ステージ選択へ.png");
}

void GameClear::Initialize()
{
	TextureLoad();
	_firstButtonPos = Vector2(400, 300);
	_secondButtonPos = Vector2(400, 500);
	Vector2 _size = Vector2(300, 120);

	_nextStageButton.SetStatu(_firstButtonPos, &_nextStageTexture);
	_stageSelectButton.SetStatu(_secondButtonPos, &_stageSelectTexture);
	_goal = false;
	_mousePos = Vector2(0, 0);
}

void GameClear::Reload()
{
	_goal = false;
}

void GameClear::Update()
{
	if (IsGoal())
	{
		g_pInput->GetMousePos(_mousePos);
		if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
		{
			if (_nextStageButton.CheckOnButton(_mousePos))
			{
				//次のステージへ
				dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StartNextStage();
			}
			
			if (_stageSelectButton.CheckOnButton(_mousePos))
			{
				SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
			}
		}
	}
}

void GameClear::Render()
{
	if (IsGoal())
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
		_nextStageButton.Render();
		_stageSelectButton.Render();
	}
}

void GameClear::Release()
{
	_nextStageTexture.Release();
	_stageSelectTexture.Release();
}
