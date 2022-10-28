#include "InputMenu.h"

void InputMenu::Update() {
	
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) {
		g_pInput->GetMousePos(_mousePos);

		_settingManager->Push(_mousePos);
	}
}