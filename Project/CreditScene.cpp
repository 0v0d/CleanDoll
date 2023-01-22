#include "CreditScene.h"
#include "SceneManager.h"

void CreditScene::Initialize() {
	LoadTexture();
	LoadSound();
	_titleButton.SetTexture(&_buttonTexture);
	_titleButton.SetPosition(Vector2(100, 100));
	_titleButton.SetSeSound(&_buttonSe);
	_titleButton.SetStatu(false, true, [&]() {SceneManager::Instance().ChangeScene(SCENE_TYPE::TITLE); });
}

void CreditScene::ReLoad() {
}

void CreditScene::LoadTexture() {
	_buttonTexture.Load("backSceneButton.png");
}

void CreditScene::LoadSound() {
	_music.Load("BGM.mp3");
	_buttonSe.Load("BottanClick.mp3");
}

void CreditScene::SetMousePos(Vector2 mousePos) {
	_titleButton.SetMousePos(mousePos);
}

void CreditScene::Push() {
	_titleButton.Push();
}

void CreditScene::Pull() {
	_titleButton.Pull();
}

void CreditScene::Update() {
}

void CreditScene::Render() {
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(200, 10,10, 10));
	CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth()/2 -200, g_pGraphics->GetTargetHeight() / 2, "\nBGM\nŠÃ’ƒ‚Ì‰¹ŠyH–[\nhttps://amachamusic.chagasi.com/index.htm\nSE\nŒø‰Ê‰¹ƒ‰ƒ{\nhttps ://soundeffect-lab.info/");
	_titleButton.Render();
}

void CreditScene::Release() {
	_buttonTexture.Release();
	_buttonSe.Release();
	_music.Release();
}
