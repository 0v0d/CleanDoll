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
		_barManager->PushBar(_mousePos);
		_slider->PushSlider();
	}
	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON))
	{
		_slider->PullSlider();
	}
	if (g_pInput->IsMouseKeyPush(MOFMOUSE_RBUTTON))
	{
		_barManager->PickStage(_mousePos);
	}
	

}