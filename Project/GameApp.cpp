#include	"GameApp.h"
#include	"SceneManager.h"

MofBool CGameApp::Initialize(void){
	CUtilities::SetCurrentDirectory("Resource");
	SceneManager::Instance().Initialize();
	return TRUE;
}
MofBool CGameApp::Update(void){
	g_pInput->RefreshKey();

	SceneManager::Instance().Update();
	return TRUE;
}
MofBool CGameApp::Render(void){
	g_pGraphics->RenderStart();
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);

	SceneManager::Instance().Render();
	g_pGraphics->RenderEnd();
	return TRUE;
}
MofBool CGameApp::Release(void){

	SceneManager::Instance().Release();
	return TRUE;
}