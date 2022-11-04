#include "GameOver.h"

void GameOver::Initialize()
{
	TextureLoad();
	_RetrunStageSelect.Initialize();
	_nextStage.Initialize();
	_retryGame.Initialize();
	_goal = false;
	_mousePos = Vector2(0, 0);
}

void GameOver::Reload()
{
	_goal = false;
}

void GameOver::Update()
{
	g_pInput->GetMousePos(_mousePos);
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
	{
		_nextStage.ClickButton(_mousePos);
		_RetrunStageSelect.ClickButton(_mousePos);
	}
}

void GameOver::Render()
{
	if (IsGoal())
	{
		_nextStage.Render();
		_RetrunStageSelect.Render();
	}
}

void GameOver::Release()
{

}

void GameOver::TextureLoad()
{

}
