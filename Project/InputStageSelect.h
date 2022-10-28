#pragma once
#include <string>

#include "BarManager.h"
#include "Slider.h"

class InputStageSelect
{
private:
	BarManager* _barManager;
	Slider* _slider;
	Vector2 _mousePos;
public:
	void SetBarManager(BarManager* barManager) { _barManager = barManager; }
	void SetSlider(Slider* slider) { _slider = slider; }
	void Update();
private:
	void InputMouse();
};
