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
	
	_logoAnim.Initialize();
	_retryPos = Vector2(400, 300);
	_stageSelectPos = Vector2(400, 500);
	_button[0].SetStatu(_retryPos, &_retryTexture);
	_button[1].SetStatu(_stageSelectPos, &_stageSelectTexture);
	_endButton[0].SetStatu(_retryPos, &_retryTexture);
	_endButton[1].SetStatu(_stageSelectPos, &_stageSelectTexture);

	_retryButton.SetTexture(&_retryTexture);
	_retryButton.SetPosition(_firstButtonPos);
	_stageSelectButton.SetTexture(&_stageSelectTexture);
	_stageSelectButton.SetPosition(_secondButtonPos);
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
	if (_backGround.IsEndeMotion())
	{
		_logoAnim.Update();
	}
	else
	{
		_backGround.Update();
	}
	
	
	if (_logoAnim.IsEndeMotion())
	{
		for (int i = 0; i < _menuValue; i++)
		{
			_endButton[i].Update();
		}
	}

}

void GameOver::SetMousePos(Vector2 mousePos) {
	_retryButton.SetMousePos(mousePos);
	_stageSelectButton.SetMousePos(mousePos);
}

void GameOver::Push() {
	_retryButton.Push();
	_stageSelectButton.Push();
}

void GameOver::Pull() {
	_retryButton.Pull();
	_stageSelectButton.Pull();

	if (_retryButton.IsPullButton()) {
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
	}
	if (_stageSelectButton.IsPullButton()) {
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
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
		for (int i = 0; i < _menuValue; i++)
		{
			_endButton[i].Render();
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