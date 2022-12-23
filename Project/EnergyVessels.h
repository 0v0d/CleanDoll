#pragma once
#include	"Mof.h"
#include	"EnergyBar.h"
#include "EnergyValue.h"
#include	"map"
class EnergyVessels
{
private:
	EnergyValue _energyValue;
	int _currentEnergyValue, _maxEnergyValue;

	EnergyBar* _energyBarArray = nullptr;
	CTexture _energyVesselsTexture, _energyBarTexture, _remainEnergyTexture, _energyVesselsCenterTexture;
	Vector2 _vesselsPosition,_remainPosition, _energyVesselsCenterPosition;

	const float _energyVesselsScale = 0.2f;
	float _remainEnergyScale;

	const int _variationValue = 3;
	std::map<int, MofU32> _renderColorArray;

public:
	void Initialize();
	void ReLoad();
	void SetMaxEnergyValue(int energyValue);
	
	void Update();
	void SetCurrentEnergyValue(int currentEnergyValue);

	void Render();
	void Release();
	
private:
	void LoadTexture();
	void CreateEnergyBarArray();
	void SetBarStatu();
	void ChangeEnergyColor();
	void CalucScale();
	void CalucPosition();
};