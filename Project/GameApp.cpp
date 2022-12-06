#include	"GameApp.h"
#include	"SceneManager.h"

MofBool CGameApp::Initialize()
{
	_input.SetMenu(&_menu);
	CUtilities::SetCurrentDirectory("Resource");
	SceneManager::Instance().Initialize();
	_menu.Initialize();
	_exit.Initialize();
	return TRUE;
}

MofBool CGameApp::Update()
{
	g_pInput->RefreshKey();
	g_pInput->GetMousePos(_mousePos);
	_input.Update();
	
	if (!_exit.IsOpenExitDialog()) {
		if (!_menu.IsOpenMenu())SceneManager::Instance().Update();
		_menu.Update();
		_exit.Update();
	}
	if (_exit.IsOpenExitDialog()) {
		_exit.Push(_mousePos);
	}
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
	_exit.Render();
	g_pGraphics->RenderEnd();
	return TRUE;
}

MofBool CGameApp::Release()
{
	SceneManager::Instance().Release();
	_menu.Release();
	_exit.Release();
	return TRUE;
}