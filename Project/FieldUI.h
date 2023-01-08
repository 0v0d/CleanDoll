#pragma once
#include "EnergyVessels.h"
#include "GameClearButton.h"
#include "RemainingDumpUI.h"

class FieldUI
{
	RemainingDumpUI _remainingDumpUI;
	EnergyVessels _energyVessels;
	GameClearButton _gameClearButton;
public:
	void Initialize();
	void ReLoad();
	void SetMaxEnergyValue(int energyValue);
	void SetDustDumpValue(int dumpValue);
	void SetWaterDumpValue(int dumpValue);
	void GettedGalleryCoin() { _remainingDumpUI.GettedCoin(); }
	void Pull();
	void SetMousePos(Vector2 mousePos);
	void Update();
	void SetCurrentEnergyValue(int energyValue);
	void CleanDust();
	void CleanWater();
	void GetGalleryCoin() { _remainingDumpUI.MarkIcon(ICON_TYPE::COIN); }

	bool IsPull() { return _gameClearButton.IsPull(); }

	void Render();
	void Release();
};