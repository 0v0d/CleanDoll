#include "EndTutorial.h"

void EndTutorial::Initialize(){
	LoadTexture();
	_endGameButton.Initialize();
	Vector2 _stageSelectButtonPos = Vector2(400, 500);
	_endGameButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
	_stageSelectButton.SetTexture(&_stageSelectTexture);
	_stageSelectButton.SetPosition(_stageSelectButtonPos);
	_endGameButton.SetStatu(_stageSelectButtonPos, &_stageSelectTexture);
}

void EndTutorial::LoadTexture(){
	_stageSelectTexture.Load("ステージ選択に戻る.png");
}

void EndTutorial::ReLoad(){

}

void EndTutorial::Update(){
	if (!_endGameButton.IsEndAnimation());
}

void EndTutorial::SetMousePos(Vector2){

}

void EndTutorial::Push(){
}

void EndTutorial::Pull(){
}

void EndTutorial::Render(){

}

void EndTutorial::Release(){
	_stageSelectTexture.Release();
}


