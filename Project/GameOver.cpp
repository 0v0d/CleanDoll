#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	LoadTexture();
	_backGround.Initialize();
	_logoAnim.Initialize();
	_retryPos = Vector2(400, 300);
	_stageSelectPos = Vector2(400, 500);
	_button[0].SetStatu(_retryPos, &_retryTexture);
	_button[1].SetStatu(_stageSelectPos, &_stageSelectTexture);

}

void GameOver::LoadTexture()
{
	_retryTexture.Load("ステージ選択へ.png");
	_stageSelectTexture.Load("ステージ選択へ.png");
}

void GameOver::ReLoad()
{

}

void GameOver::Update()
{
	if (_backGround.IsEndeMotion())
	{
		_logoAnim.Update();
	}
	else
	{
		_backGround.Update();
	}
}

void GameOver::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
}

void GameOver::Push() {
	if (_button[0].CheckOnButton(_mousePos))
	{
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}

	if (_button[1].CheckOnButton(_mousePos))
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void GameOver::Pull() {

}

void GameOver::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_backGround.Render();
	
	if(_backGround.IsEndeMotion())
	{
		_logoAnim.Render();
	}
	
	if (_logoAnim.IsEndeMotion())
	{
		for (int i = 1; i < _menuValue; i++)
		{
			_button[i].Render();
		}
	}
	
}

void GameOver::Release()
{
	_backGround.Release();
	_logoAnim.Release();
	_retryTexture.Release();
	_stageSelectTexture.Release();
}