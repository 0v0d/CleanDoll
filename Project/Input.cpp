#include "Input.h"
#include "SceneManager.h"

void Input::Update() {
	InputMouse();
	InputKey();
}

void Input::InputMouse() {

	SetMousePos();

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) {
		Push();
	}
	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON)) {
		Pull();
	}
}

void Input::InputKey() {
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE)) {
		_exitGame->OpenExitDialog();
	}
}

void Input::SetMousePos() {
	g_pInput->GetMousePos(_mousePos);

	if (_exitGame->IsOpenExitDialog()) {
		_exitGame->SetMousePos(_mousePos);
		return;
	}

	_menu->SetMousePos(_mousePos);
	if (_menu->IsOpenMenu()) return;

	SceneManager::Instance().SetMousePos(_mousePos);
}

void Input::Push() {
	if (_exitGame->IsOpenExitDialog()) {
		_exitGame->Push();
		return;
	}

	_menu->Push();

	if (_menu->IsOpenMenu()) return;
	SceneManager::Instance().Push();
}

void Input::Pull() {
	if (_exitGame->IsOpenExitDialog()) {
		_exitGame->Pull();
		return;
	}

	_menu->Pull();
	if (_menu->IsOpenMenu()) return;

	SceneManager::Instance().Pull();
}