#include	"GameApp.h"
#include	"SceneManager.h"

MofBool CGameApp::Initialize()
{
	CUtilities::SetCurrentDirectory("Resource");
	SceneManager::Instance().Initialize();
	_menu.Initialize();
	return TRUE;
}

MofBool CGameApp::Update()
{
	g_pInput->RefreshKey();
	if (!_menu.IsOpenMenu())SceneManager::Instance().Update();
	_menu.Update();
	return TRUE;
}

MofBool CGameApp::Render()
{
	g_pGraphics->RenderStart();
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);

	SceneManager::Instance().Render();
	SCENE_TYPE currentSceneType = SceneManager::Instance().GetCurrentSceneType();
	if (currentSceneType == SCENE_TYPE::STAGESELECT || currentSceneType == SCENE_TYPE::GAME) {
		_menu.Render();
	}

	g_pGraphics->RenderEnd();
	return TRUE;
}

MofBool CGameApp::Release()
{
	SceneManager::Instance().Release();
	_menu.Release();
	return TRUE;
}