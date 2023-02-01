#pragma once
#include	"EnergyVessels.h"
class EnergyAnimation
{
	EnergyVessels* _energyVessels;
	int _energyValue;
	int _time,_addEnergyTime;
	int _count,_energyCount;
	bool _end;

public:
	EnergyAnimation();
	void SetEnergyVessels(EnergyVessels* energyVess) { _energyVessels = energyVess; }
	void SetStatu(int time, int energyVal);
	void Start();
	void Update();

	bool IsEnd() { return _end; }
};