#include "FieldUI.h"

void FieldUI::Initialize(){
	_energyVessels.Initialize();
	_remainingDumpUI.Initialize();
}

void FieldUI::ReLoad(){
	_energyVessels.ReLoad();
	_remainingDumpUI.ReLoad();
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