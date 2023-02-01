#include "GameClear.h"
#include "SceneManager.h"
#include "StageSelectScene.h"

void GameClear::Initialize()
{
	LoadTexture();
	_dollAnim.Initialize();
	_endGameButtonManager.Initialize();

	CreateButtonArray();
}

void GameClear::LoadTexture()
{
	_nextStageTexture.Load("次のステージ.png");
	_stageSelectTexture.Load("ステージ選択に戻る.png");
	_retryTexture.Load("ステージをやり直す.png");
}

void GameClear::CreateButtonArray() {
	float posX = 200;
	Vector2 nextButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - posX, 400);
	Vector2 stageSelectButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - posX, 600);
	Vector2 retryButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - posX, 800);

	const float targetSizeY = 80;
	_endGameButtonManager.CreateButton(&_nextStageTexture, 0, targetSizeY, nextButtonPos, [&]() {
		dynamic_cast<StageSelectScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::STAGESELECT))->StartNextStage();
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
		});

	_endGameButtonManager.CreateButton(&_stageSelectTexture, 0, targetSizeY, stageSelectButtonPos, [&]() {
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
		});

	_endGameButtonManager.CreateButton(&_retryTexture, 0, targetSizeY, retryButtonPos, [&]() {
		SceneManager::Instance().GetScene(SCENE_TYPE::GAME)->ReLoad();
		});
}

void GameClear::ReLoad() {
	_clearAnimation->ReLoad();
	_dollAnim.ReLoad();

	_endGameButtonManager.ReLoad();
}

void GameClear::Update()
{
	UpdateAnimation();
}

void GameClear::UpdateAnimation() {

	if (!_clearAnimation->IsEndMotion()) {
		_clearAnimation->Update();
		return;
	}

	_dollAnim.Update();
	_endGameButtonManager.Update();
}

void GameClear::SetMousePos(Vector2 mousePos) {
	_endGameButtonManager.SetMousePos(mousePos);
}

void GameClear::Push() {
	_endGameButtonManager.Push();
}

void GameClear::Pull() {
	_endGameButtonManager.Pull();
}

void GameClear::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(210, 0, 0, 0));
	_clearAnimation->Render();

	if (!_clearAnimation->IsEndMotion()) return;

	_dollAnim.Render();
	_endGameButtonManager.Render();
}

void GameClear::Release()
{
	_dollAnim.Release();
	_endGameButtonManager.Release();

	_nextStageTexture.Release();
	_stageSelectTexture.Release();
	_retryTexture.Release();
}