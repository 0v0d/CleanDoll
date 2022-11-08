#include "TitleScene.h"

void TitleScene::Initialize()
{
	Load();
	_titleBackRect = CRectangle(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
}
void TitleScene::Load()
{
	_titleBackTexture.Load("menu_back.png");
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
	_titleBackTexture.Render(0, 0, _titleBackRect);
	CGraphicsUtilities::RenderString(30, 30, "TitleScene");
}

void TitleScene::Release()
{
	_titleBackTexture.Release();
}