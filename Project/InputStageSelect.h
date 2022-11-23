#pragma once
#include "BarManager.h"
#include "Slider.h"
#include "StageSelectDialog.h"

class InputStageSelect
{
private:
	BarManager* _barManager;
	StageSelectDialog* _stageSelectDialog;
	Vector2 _mousePos;
public:
	void SetBarManager(BarManager* barManager) { _barManager = barManager; }
	void SetStageSelectDialog(StageSelectDialog* stageSelectDialg) { _stageSelectDialog = stageSelectDialg; }
	void Update();
private:
	void InputMouse();
};
