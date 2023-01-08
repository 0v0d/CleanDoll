#include "FieldUI.h"

void FieldUI::Initialize(){
	_energyVessels.Initialize();
	_remainingDumpUI.Initialize();
	_gameClearButton.Initialize();
}

void FieldUI::ReLoad(){
	_energyVessels.ReLoad();
	_remainingDumpUI.ReLoad();
	_gameClearButton.ReLoad();
}

void FieldUI::SetMousePos(Vector2 mousePos) {
	_gameClearButton.SetMousePos(mousePos);
}

void FieldUI::Push() {
	_gameClearButton.Push();
}

void FieldUI::Pull() {
	_gameClearButton.Pull();
}

void FieldUI::SetMaxEnergyValue(int energyValue) {
	_energyVessels.SetMaxEnergyValue(energyValue);
}

void FieldUI::SetDustDumpValue(int dumpValue) {
	_remainingDumpUI.SetDustValue(dumpValue);
	_gameClearButton.SetDustValue(dumpValue);
}

void FieldUI::SetWaterDumpValue(int dumpValue) {
	_remainingDumpUI.SetWaterValue(dumpValue);
	_gameClearButton.SetWaterValue(dumpValue);
}

void FieldUI::Update(){
	_remainingDumpUI.Update();
	_gameClearButton.Update();
}

void FieldUI::CleanDust() {
	_remainingDumpUI.CleanDust();
	_gameClearButton.CleanDust();
}

void FieldUI::CleanWater() {
	_remainingDumpUI.CleanWater();
	_gameClearButton.CleanWater();
}

void FieldUI::SetCurrentEnergyValue(int energyValue) {
	_energyVessels.SetCurrentEnergyValue(energyValue);
}

void FieldUI::Render(){
	_gameClearButton.Render();
	_energyVessels.Render();
	_remainingDumpUI.Render();
}

void FieldUI::Release(){
	_energyVessels.Release();
	_remainingDumpUI.Release();
	_gameClearButton.Release();
}