#include "InputStageSelect.h"

void InputStageSelect::Update()
{
	InputMouse();
}

void InputStageSelect::InputMouse()
{
	g_pInput->GetMousePos(_mousePos);

	if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
	{
		_barManager->Push(_mousePos);
	}
	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON))
	{
		_barManager->Pull(_mousePos);
	}
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_RBUTTON))
	{
		_barManager->PickStage(_mousePos);
	}
	

}