#pragma once
#include "EnergyVessels.h"
#include "RemainingDumpUI.h"

class FieldUI
{
	RemainingDumpUI _remainingDumpUI;
	EnergyVessels _energyVessels;
public:
	void Initialize();
	void ReLoad();
	void StartSlideInUI();
	void SetMaxEnergyValue(int energyValue);
	void SetDustDumpValue(int dumpValue);
	void SetWaterDumpValue(int dumpValue);
	void GetGalleryCoin() { _remainingDumpUI.GetCoin(); }
	void Update();
	void SetCurrentEnergyValue(int energyValue);
	void CleanDust();
	void CleanWater();
	void Render();
	void Release();
};