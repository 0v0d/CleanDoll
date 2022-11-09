#include "TitleScene.h"

void TitleScene::Initialize()
{
	_titleBackTexture.Load("titleback.png");
	_backGround.SetTextureName(&_titleBackTexture);
}


void TitleScene::ReLoad()
{

}

void TitleScene::Update()
{
	InputMouseKey();
}

void TitleScene::InputMouseKey()
{

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON) || g_pInput->IsMouseKeyPush(MOFMOUSE_RBUTTON))
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
}

void TitleScene::Render()
{
	_backGround.Render();
	CGraphicsUtilities::RenderString(30, 30, "TitleScene");
}

void TitleScene::Release()
{
	_titleBackTexture.Release();
}