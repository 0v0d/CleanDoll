#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void GameClear::Initialize()
{
	TextureLoad();
	_firstButtonPos = Vector2(400, 300);
	_secondButtonPos = Vector2(400, 500);
	Vector2 _size = Vector2(300, 120);
	Vector2 _size2 = Vector2(300, 120);
	_nextStageButton.SetStatu(_firstButtonPos, _size);
	_stageSelectButton.SetStatu(_secondButtonPos, _size2);
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
		_nextStageButton.Render();
		_stageSelectButton.Render();
	}
}

void GameClear::Release()
{

}

void GameClear::TextureLoad()
{

}