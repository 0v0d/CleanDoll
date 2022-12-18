#include "GameOver.h"
#include "SceneManager.h"

void GameOver::Initialize()
{
	LoadTexture();
	_backGround.Initialize();
	_logoAnim.Initialize();

	CreateButtonArray();
}

void GameOver::LoadTexture()
{
	_retryTexture.Load("ステージをやり直す.png");
	_stageSelectTexture.Load("ステージ選択に戻る.png");
}

void GameOver::CreateButtonArray() {

	float posX = 200;
	Vector2 retryButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - posX, 300);
	Vector2 stageSelectButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - posX, 500);

	const float targetSizeY = 80;
	_endGameButtonManager.CreateButton(&_retryTexture, 0, targetSizeY, retryButtonPos, [&]() {
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
		});

	_endGameButtonManager.CreateButton(&_stageSelectTexture, 0, targetSizeY, stageSelectButtonPos, [&]() {
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
		});
}


void GameOver::ReLoad()
{
	_backGround.ReLoad();
	_logoAnim.ReLoad();
	_endGameButtonManager.ReLoad();
}

void GameOver::Update()
{
	UpdateAnimation();
}

void GameOver::UpdateAnimation() {
	if (_endGameButtonManager.IsEndAnimation()) return;
		
	if (!_backGround.IsEndMotion()){
		_backGround.Update();
		return;
	}

	if (!_logoAnim.IsEndMotion()){
		_logoAnim.Update();
		return;
	}

	_endGameButtonManager.Update();
}

void GameOver::SetMousePos(Vector2 mousePos) {
	_endGameButtonManager.SetMousePos(mousePos);
}

void GameOver::Push() {
	_endGameButtonManager.Push();
}

void GameOver::Pull() {
	_endGameButtonManager.Pull();
}

void GameOver::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_backGround.Render();
	_logoAnim.Render();

	if (!_logoAnim.IsEndMotion()) return;
	
	_endGameButtonManager.Render();
}

void GameOver::Release()
{
	_backGround.Release();
	_logoAnim.Release();

	_endGameButtonManager.Release();

	_retryTexture.Release();
	_stageSelectTexture.Release();
}