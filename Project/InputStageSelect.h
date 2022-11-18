#pragma once
#include "BarManager.h"
#include "Slider.h"
#include "StageSelectDialog.h"

class InputStageSelect
{
private:
	BarManager* _barManager;
	Slider* _slider;
	StageSelectDialog  *_stageSD;
	Vector2 _mousePos;
public:
	void SetBarManager(BarManager* barManager) { _barManager = barManager; }
	void SetSlider(Slider* slider) { _slider = slider; }
	void SetDialogButton(StageSelectDialog* stageselectdialog) { _stageSD = stageselectdialog; }
	void Update();
private:
	void InputMouse();
};
