#include "EndTutorial.h"

void EndTutorial::Initialize()
{
	LoadTexture();
	_endButtonAnimation.Initialize();
	Vector2 stageSelectPos = Vector2(400, 500);
	_endButtonAnimation.SetStatu(stageSelectPos, &_stageSelectTexture);
	_stageSelectButton.SetTexture(&_stageSelectTexture);
	_stageSelectButton.SetPosition(stageSelectPos);
}

void EndTutorial::LoadTexture()
{
	_stageSelectTexture.Load("ステージ選択に戻る.png");
}

void EndTutorial::ReLoad()
{

}

void EndTutorial::Update()
{
	if (!_endButtonAnimation.IsEndAnimation());
}

void EndTutorial::SetMousePos(Vector2)
{
}

void EndTutorial::Push()
{
}

void EndTutorial::Pull()
{
}

void EndTutorial::Render()
{
}

void EndTutorial::Release()
{
}


