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
		if (!_stageSD->IsOpenStDialog()) {
			_slider->PushSlider();
			
			_barManager->PushBar(_mousePos);
			_stageSD->SetStageNumber(_barManager->GetPushBarNumber(_mousePos));
		}
		else {
			
			_stageSD->CloseDialog(_mousePos);
		}

		if (_stageSD->IsOpenStDialog()) {
			if (_stageSD->CheckYesButton(_mousePos))
				_barManager->PickStage(_stageSD->GetStageNumber());
		}
	}

	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON))
	{
		_slider->PullSlider();
	}
}