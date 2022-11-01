#include "InputMenu.h"

void InputMenu::Update()
{
	g_pInput->GetMousePos(_mousePos);

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
	{
		_settingManager->Push(_mousePos);
	}
	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON))
	{
		_settingManager->Pull(_mousePos);
	}
}