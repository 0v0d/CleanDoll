#include "GameClear.h"

#include "SceneManager.h"

void GameClear::Initialize()
{
	TextureLoad();
	_RetrunStageSelect.Initialize();
	_nextStage.Initialize();
	_goal = false;
	_mousePos = Vector2(0, 0);
}

void GameClear::Reload()
{
	_goal = false;
}

void GameClear::Update()
{
	g_pInput->GetMousePos(_mousePos);
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
	{
		if(_nextStage.CheckOnMouse(_mousePos))
		{
			//次のステージへ
		}
		if (_RetrunStageSelect.CheckOnMouse(_mousePos))
		{
			SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
		}
	}
		
}

void GameClear::Render()
{
	if(IsGoal())
	{
		_nextStage.Render();
		_RetrunStageSelect.Render();
	}
}

void GameClear::Release()
{
	
}

void GameClear::TextureLoad()
{
	
}
