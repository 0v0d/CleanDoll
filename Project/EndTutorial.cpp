#include "EndTutorial.h"
#include "SceneManager.h"

void EndTutorial::Initialize(){
	LoadTexture();

	Vector2 _stageSelectButtonPos = Vector2(g_pGraphics->GetTargetWidth()/2 - _stageSelectTexture.GetWidth()/2, g_pGraphics->GetTargetHeight()/2);

	_clearAnimation.Initialize();
	_dollAnim.Initialize();
	_endGameButtonManager.Initialize();

	CreateButtonArray();
}

void EndTutorial::LoadTexture(){
	_stageSelectTexture.Load("ステージ選択に戻る.png");
}

void EndTutorial::CreateButtonArray() {
	float posX = 200;
	Vector2 stageSelectButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - posX, 600);

	const float targetSizeY = 80;
	_endGameButtonManager.CreateButton(&_stageSelectTexture, 0, targetSizeY, stageSelectButtonPos, [&]() {
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
		});
}

void EndTutorial::ReLoad(){
	_clearAnimation.ReLoad();
}

void EndTutorial::Update(){
	UpdateAnimation();
}

void EndTutorial::UpdateAnimation()
{
	if (!_clearAnimation.IsEndMotion()) {
		_clearAnimation.Update();
		return;
	}
	_dollAnim.Update();
	_endGameButtonManager.Update();
}

void EndTutorial::SetMousePos(Vector2 mousePos) {
	_endGameButtonManager.SetMousePos(mousePos);
}

void EndTutorial::Push() {
	_endGameButtonManager.Push();
}

void EndTutorial::Pull() {
	_endGameButtonManager.Pull();
}

void EndTutorial::Render(){
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(210, 0, 0, 0));
	_clearAnimation.Render();

	if (!_clearAnimation.IsEndMotion()) return;

	_dollAnim.Render();
	_endGameButtonManager.Render();
}

void EndTutorial::Release(){
	_stageSelectTexture.Release();
	_clearAnimation.Release();
	_dollAnim.Release();
	

	_endGameButtonManager.Release();
}