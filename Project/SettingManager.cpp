#include "SettingManager.h"

void SettingManager::Initialize()
{
	_setUpSetting.SetOpenMenu(&_openMenu);
	_setUpSetting.Initialize();
	CreateButton();
	LoadTexture();
	LoadSound();
	_openMenu = false;
}

void SettingManager::LoadTexture() {
	_menuTexture.Load("ƒƒjƒ…[@UI.png");
	_openButtonTexture.Load("Ý’èƒƒS.png");

}

void SettingManager ::LoadSound () {
	_buttonSe.Load("BottanClick.mp3");
}

void SettingManager::CreateButton() {

	_openSettingButton.SetTexture(&_openButtonTexture);
	_openSettingButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() - 90, 70));
	_openSettingButton.SetSeSound(&_buttonSe);
	_openSettingButton.SetStatu(false, true, [&]() {
		_openMenu = true;
		_setUpSetting.DetermineBackScene();
		});
}

void SettingManager::Update()
{
	if (_openMenu)
	{
		_setUpSetting.Update();
	}
}

void SettingManager::SetMousePos(Vector2 mousePos) {
	_setUpSetting.SetMousePos(mousePos);
	_openSettingButton.SetMousePos(mousePos);
}

void SettingManager::Push() {
	if (!_openMenu)
	{
		_openSettingButton.Push();
	}
	else
	{
		_setUpSetting.Push();
	}
}

void SettingManager::Pull() {
	if (!_openMenu) {
		_openSettingButton.Pull();
	}
	else{
		_setUpSetting.Pull();
	}
}

void SettingManager::Render()
{
	_openSettingButton.Render();
	if (_openMenu)
	{
		CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(210, 0, 0, 0));
		_setUpSetting.Render();
		if(!_setUpSetting.IsOpenSetting())_menuTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _menuTexture.GetWidth() / 2, 50);
	}
}

void SettingManager::Release()
{
	_setUpSetting.Release();
	_buttonSe.Release();
	_menuTexture.Release();
	_openButtonTexture.Release();
}