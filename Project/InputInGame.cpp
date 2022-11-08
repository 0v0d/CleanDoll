#include "InputInGame.h"

void InputInGame::Update()
{
	g_pInput->GetMousePos(_mousePosition);

	InputKey();
	InputMouse();
}

void InputInGame::InputKey()
{

}

void InputInGame::InputMouse()
{
	if (g_pInput->IsMouseKeyHold(MOFMOUSE_LBUTTON))
	{
		PassedBlock();
	}
	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON))
	{
		_field->EndOfPassed();
	}
}

void InputInGame::PassedBlock()
{
	_field->PassedMouse(_mousePosition);
}