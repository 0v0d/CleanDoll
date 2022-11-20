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
		_stageSelectDialog->Push(_mousePos);
		_stageSelectDialog->SetStageNumber(_barManager->GetBarNumber(_mousePos));

		if (_stageSelectDialog->GetStageNumber()!=-1)_barManager->SetPreview(_stageSelectDialog->GetStageNumber());

		if (_stageSelectDialog->CheckPushYesButton()) {
			_barManager->StartStage(_stageSelectDialog->GetStageNumber());
		}
	}
	if (g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON))
	{
		_barManager->Pull(_mousePos);
	}
}