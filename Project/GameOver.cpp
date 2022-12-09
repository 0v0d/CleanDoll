#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	LoadTexture();
	_backGround.Initialize();
	for (int i = 0; i < _menuValue; i++)
	{
		_endButton[i].Initialize();
	}
	
	_retryPos = Vector2(400, 300);
	_stageSelectPos = Vector2(400, 500);
	_button[0].SetStatu(_retryPos, &_retryTexture);
	_button[1].SetStatu(_stageSelectPos, &_stageSelectTexture);
	_endButton[0].SetStatu(_retryPos, &_retryTexture);
	_endButton[1].SetStatu(_stageSelectPos, &_stageSelectTexture);

}

void GameOver::LoadTexture()
{
	_retryTexture.Load("ステージをやり直す.png");
	_stageSelectTexture.Load("ステージ選択に戻る.png");
}

void GameOver::ReLoad()
{

}

void GameOver::Update()
{
	_backGround.Update();
	//失敗のテロップが終わったらという条件文に変える。
	if (_backGround.IsEndeMotion())
	{
		for (int i = 0; i < _menuValue; i++)
		{
			_endButton[i].Update();
		}
	}
}

void GameOver::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
}

void GameOver::Push() {
	if (_endButton[0].IsEndAnimation())
	{
		if (_button[0].CheckOnButton(_mousePos))
		{
			SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
		}

		if (_button[1].CheckOnButton(_mousePos))
		{
			SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
		}
	}
}

void GameOver::Pull() {

}

void GameOver::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_backGround.Render();
	for (int i = 0; i < _menuValue; i++)
	{
		_endButton[i].Render();
	}
}

void GameOver::Release()
{
	_backGround.Release();
	_retryTexture.Release();
	_stageSelectTexture.Release();
}