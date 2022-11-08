#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	TextureLoad();
	_firstButtonPos = Vector2(400, 300);
	_secondButtonPos = Vector2(400, 500);
	_retryButton.SetStatu(_firstButtonPos, &_retryTexture);
	_stageSelectButton.SetStatu(_secondButtonPos, &_stageSelectTexture);
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
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
		_retryButton.Render();
		_stageSelectButton.Render();
	}
}

void GameOver::Release()
{
	_retryTexture.Release();
	_stageSelectTexture.Release();
}

void GameOver::TextureLoad()
{
	_retryTexture.Load("ステージ選択へ.png");
	_stageSelectTexture.Load("ステージ選択へ.png");
}
