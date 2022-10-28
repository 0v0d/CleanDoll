#pragma once
#include	"Mof.h"
#include	"EnergyBar.h"
#include	"DollOnEnergyVessels.h"
#include	"map"
class EnergyVessels
{
	DollOnEnergyVessels _dollOnEnergyVessels;

	int* _currentEnergyValue;
	int _maxEnergyValue;
	EnergyBar* _energyBarArray = nullptr;
	CTexture _energyVesselsTexture, _energyBarTexture, _remainEnergyTexture;
	Vector2 _vesselsPosition,_remainPosition;

	float _scale = 0.4f;

	const int _variationValue = 3;
	std::map<int, MofU32> _renderColorArray;

public:
	void Initialize();
	void SetMaxEnergyValue(int energyValue);
	void SetCurrentEnergyValue(int* currentEnergyValue) { _currentEnergyValue = currentEnergyValue; }
	
	void Update();
	void CheckChangeEnergyColor();

	void Render();
	void Release();

private:
	void LoadTexture();
	void CreateEnergyBarArray();
	void SetBarStatu();
};