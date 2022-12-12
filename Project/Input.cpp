#include "Input.h"
#include "SceneManager.h"

void Input::Update() {
	InputMouse();
	InputKey();
}

void Input::InputMouse() {

	g_pInput->GetMousePos(_mousePos);
	SceneManager::Instance().SetMousePos(_mousePos);
	_exitGame->SetMousePos(_mousePos);
	_menu->SetMousePos(_mousePos);

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) {
		
		SceneManager::Instance().Push();
		_exitGame->Push();
		_menu->Push();
	}

	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON)) {
		SceneManager::Instance().Pull();
		_exitGame->Pull();
		_menu->Pull();
	}
}

void Input::InputKey() {
	if (g_pInput->IsKeyPush(MOFKEY_ESCAPE)) {
		_exitGame->OpenExitDialog();
	}
}