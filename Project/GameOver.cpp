#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	LoadTexture();
	_backGround.Initialize();
	for (int i = 0; i < _menuValue; i++)
	{
		_endButtonAnimation[i].Initialize();
	}
	
	_logoAnim.Initialize();

	Vector2 retryPos = Vector2(400, 300);
	Vector2 stageSelectPos = Vector2(400, 500);

	_endButtonAnimation[0].SetStatu(retryPos, &_retryTexture);
	_endButtonAnimation[1].SetStatu(stageSelectPos, &_stageSelectTexture);

	_retryButton.SetTexture(&_retryTexture);
	_retryButton.SetPosition(retryPos);
	_stageSelectButton.SetTexture(&_stageSelectTexture);
	_stageSelectButton.SetPosition(stageSelectPos);
}

void GameOver::LoadTexture()
{
	_retryTexture.Load("ステージをやり直す.png");
	_stageSelectTexture.Load("ステージ選択に戻る.png");
}

void GameOver::ReLoad()
{
	_backGround.ReLoad();
	_logoAnim.ReLoad();
	for (int i = 0; i < _menuValue; i++)
	{
		_endButtonAnimation[i].ReLoad();
	}
}

void GameOver::Update()
{
	if (!_endButtonAnimation[_menuValue - 1].IsEndAnimation())UpdateAnimation();
}

void GameOver::UpdateAnimation() {
	if (!_backGround.IsEndMotion())
	{
		_backGround.Update();
		return;
	}
	if (!_logoAnim.IsEndMotion())
	{
		_logoAnim.Update();
		return;
	}

	for (int i = 0; i < _menuValue; i++)
	{
		_endButtonAnimation[i].Update();
	}
}

void GameOver::SetMousePos(Vector2 mousePos) {
	_retryButton.SetMousePos(mousePos);
	_stageSelectButton.SetMousePos(mousePos);
}

void GameOver::Push() {
	if (!_endButtonAnimation[_menuValue - 1].IsEndAnimation()) return;

	_retryButton.Push();
	_stageSelectButton.Push();
}

void GameOver::Pull() {
	if (!_endButtonAnimation[_menuValue - 1].IsEndAnimation()) return;

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
	
	if(_backGround.IsEndMotion())
	{
		_logoAnim.Render();
	}
	
	if (_logoAnim.IsEndMotion())
	{
		for (int i = 0; i < _menuValue; i++)
		{
			_endButtonAnimation[i].Render();
		}
	}
}

void GameOver::Release()
{
	_backGround.Release();
	_logoAnim.Release();
	_retryTexture.Release();
	_stageSelectTexture.Release();

	delete[] _endButtonAnimation;
}