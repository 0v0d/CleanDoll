#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	TextureLoad();
	_firstButtonPos = Vector2(400, 300);
	_secondButtonPos = Vector2(400, 500);
	Vector2 _size = Vector2(300, 120);
	Vector2 _size2 = Vector2(300, 120);
	_retryButton.SetStatu(_firstButtonPos, _size);
	_stageSelectButton.SetStatu(_secondButtonPos, _size2);
	_gameOver = false;
	_mousePos = Vector2(0, 0);
}

void GameOver::Reload()
{
	_gameOver = false;
}

void GameOver::Update()
{
	if (IsGameOver())
	{
		g_pInput->GetMousePos(_mousePos);
		if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
		{
			if (_retryButton.CheckOnButton(_mousePos))
			{
				SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
			}

			if (_stageSelectButton.CheckOnButton(_mousePos))
			{
				SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
			}
		}
	}
}

void GameOver::Render()
{
	if (IsGameOver())
	{
		_retryButton.Render();
		_stageSelectButton.Render();
	}
}

void GameOver::Release()
{

}

void GameOver::TextureLoad()
{

}
