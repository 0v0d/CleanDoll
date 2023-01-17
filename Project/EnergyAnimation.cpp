#include "EnergyAnimation.h"

EnergyAnimation::EnergyAnimation() {
	_end = false;
}

void EnergyAnimation::SetStatu(int time, int energyVal) {

	_energyValue = energyVal;
	_addEnergyTime = time / _energyValue;
}

void EnergyAnimation::Start() {
	_count = 0;
	_energyCount = 0;
	_end = false;
}

void EnergyAnimation::Update() {
	if (_end) return;

	_count++;
	if (_count >= _addEnergyTime) {
		_energyCount++;
		_energyVessels->SetCurrentEnergyValue(_energyCount);
		_count = 0;

		if (_energyCount >= _energyValue) {
			_end = true;
		}
	}
}