#include "TitleScene.h"

void TitleScene::Initialize()
{

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
	CGraphicsUtilities::RenderString(30, 30, "TitleScene");
}

void TitleScene::Release()
{

}