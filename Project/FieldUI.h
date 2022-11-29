#pragma once
#include	"EnergyVessels.h"
#include	"RemainingDumpUI.h"

class FieldUI
{
	RemainingDumpUI _remainingDumpUI;
	EnergyVessels _energyVessels;
public:
	void Initialize();
	void ReLoad();
	void SetMaxEnergyValue(int energyValue);
	void SetDumpValue(int dustValue, int waterValue);

	void Update();
	void SetCurrentEnergyValue(int energyValue);
	void CleanDust() { _remainingDumpUI.CleanDust(); }
	void CleanWater() { _remainingDumpUI.CleanWater(); }

	void Render();
	void Release();
};