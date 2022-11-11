#pragma once
#include "BarManager.h"
#include "Slider.h"

class InputStageSelect
{
private:
	BarManager* _barManager;
	Vector2 _mousePos;
public:
	void SetBarManager(BarManager* barManager) { _barManager = barManager; }
	void Update();
private:
	void InputMouse();
};
