#include "StageSelect.h"
void StageSelect::Initialize()
{

}

void StageSelect::SetStageStatu(int stageValue, std::string* stageNameArray)
{
	_barManager.CreateBarArray(stageValue);
}