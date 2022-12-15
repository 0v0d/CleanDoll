#include "EndTutorial.h"

void EndTutorial::Initialize(){
	LoadTexture();
	_endGameButton.Initialize();
	Vector2 _stageSelectButtonPos = Vector2(400, 500);
	_endGameButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_stageSelectButton.SetTexture(&_stageSelectTexture);
	_stageSelectButton.SetPosition(_stageSelectButtonPos);
	_endGameButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_backGround.Initialize();
	_dollAnimation.Initialize();
	_logoAnimation.Initialize();
}

void EndTutorial::LoadTexture(){
	_stageSelectTexture.Load("ステージ選択に戻る.png");
}

void EndTutorial::ReLoad(){
	_backGround.ReLoad();
}

void EndTutorial::Update(){
	UpdateAnimation();
}

void EndTutorial::UpdateAnimation()
{
	if (!_backGround.IsFixedScale())
	{
		_backGround.Update();
	}
	else
	{
		_logoAnimation.Update();
	}

	if (_logoAnimation.IsEndeMotion())
	{
		_dollAnimation.Update();
		_endGameButton.Update();
	}
}

void EndTutorial::SetMousePos(Vector2 mousePos){
	_stageSelectButton.SetMousePos(mousePos);
}

void EndTutorial::Push(){
	_stageSelectButton.Push();
}

void EndTutorial::Pull(){
	_stageSelectButton.Pull();
	if (_stageSelectButton.IsPullButton()) {
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void EndTutorial::Render(){
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(125, 0, 0, 0));
	_backGround.Render();
	_logoAnimation.Render();
	if (_logoAnimation.IsEndeMotion())
	{
		_stageSelectButton.Render();
	}
}

void EndTutorial::Release(){
	_stageSelectTexture.Release();
	_backGround.Release();
	_dollAnimation.Release();
	_logoAnimation.Release();
}