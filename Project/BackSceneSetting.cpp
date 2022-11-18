#include "BackSceneSetting.h"

void BackSceneSetting::Initialize()
{
	_closeButton = CRectangle(g_pGraphics->GetTargetWidth() / 2 - 50, 400, g_pGraphics->GetTargetWidth() / 2 + 50, 450);
	_backButton = CRectangle(g_pGraphics->GetTargetWidth() / 2 - 50, 300, g_pGraphics->GetTargetWidth() / 2 + 50, 350);
}

void BackSceneSetting::Update(){

}

void BackSceneSetting::Push(Vector2 mousePos)
{
	PushButton(mousePos);
}

void BackSceneSetting::Pull(Vector2 mousePos)
{

}

void BackSceneSetting::SetBackScene(SCENE_TYPE backScene) {
	_backScene = backScene;
}

void BackSceneSetting::PushButton(Vector2 mousePos)
{
	if(_closeButton.CollisionPoint(mousePos))
	{
		*_openBackSceneSetting = false;
		return;
	}
	if (_backButton.CollisionPoint(mousePos)) {
		SceneManager::Instance().ChangeScene(_backScene);
		*_openMenu = false;
		*_openBackSceneSetting = false;

		return;
	}
}

void BackSceneSetting::Render()
{
	CGraphicsUtilities::RenderFillRect(_backButton, MOF_COLOR_HGREEN);
	CGraphicsUtilities::RenderFillRect(_closeButton, MOF_COLOR_HGREEN);
}

void BackSceneSetting::Release()
{

}