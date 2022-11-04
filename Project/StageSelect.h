#pragma once
#include "BarManager.h"
#include <string>

class StageSelect
{
private:
	BarManager _barManager;
public:
	void Initialize();
	void SetStageStatu(int stageValue, std::string* stageNameArray);
	void SetBarData(int barNumber, std::string _previewTextureName, std::string stageName, int difficulty, std::string stageDataTxtName);
};