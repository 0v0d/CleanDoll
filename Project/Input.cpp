#include "Input.h"
#include "SceneManager.h"

void Input::Update() {
	InputMouse();
}

void Input::InputMouse() {

	g_pInput->GetMousePos(_mousePos);
	SceneManager::Instance().SetMousePos(_mousePos);
	_menu->SetMousePos(_mousePos);

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) {
		
		SceneManager::Instance().Push();
		_menu->Push();
	}

	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON)) {
		SceneManager::Instance().Pull();
		_menu->Pull();
	}
}