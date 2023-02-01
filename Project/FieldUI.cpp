#include "FieldUI.h"

void FieldUI::Initialize(){
	_energyAnimation.SetEnergyVessels(&_energyVessels);
	_energyVessels.Initialize();
	_remainingDumpUI.Initialize();
	_energyAnimation.SetStatu(50, 8);
}

void FieldUI::ReLoad(){
	_energyVessels.ReLoad();
	_remainingDumpUI.ReLoad();
}

void FieldUI::StartSlideInUI() {
	_energyVessels.StartSlideInUI();
	_remainingDumpUI.StartSlideInUI();
}

void FieldUI::SetMaxEnergyValue(int energyValue) {
	_energyVessels.SetMaxEnergyValue(energyValue);
}

void FieldUI::SetDustDumpValue(int dumpValue) {
	_remainingDumpUI.SetDustValue(dumpValue);
}

void FieldUI::SetWaterDumpValue(int dumpValue) {
	_remainingDumpUI.SetWaterValue(dumpValue);
}

void FieldUI::Update(){

	bool endSlide = _energyVessels.IsEndSlide();
	_energyVessels.Update();
	_remainingDumpUI.Update();
	_energyAnimation.Update();

	if (!endSlide) {
		if (_energyVessels.IsEndSlide()) {
			_energyAnimation.Start();
		}
	}
}

void FieldUI::CleanDust() {
	_remainingDumpUI.CleanDust();
}

void FieldUI::CleanWater() {
	_remainingDumpUI.CleanWater();
}

void FieldUI::SetCurrentEnergyValue(int energyValue) {
	_energyVessels.SetCurrentEnergyValue(energyValue);
}

void FieldUI::Render(){
	_energyVessels.Render();
	_remainingDumpUI.Render();
}

void FieldUI::Release(){
	_energyVessels.Release();
	_remainingDumpUI.Release();
}