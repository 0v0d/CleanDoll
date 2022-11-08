#include "GetDataFromFile.h"

void GetDataFromFile::Initialize()
{
	_contactFile.Initialize();
}

void GetDataFromFile::SetBarManager(BarManager* barManager)
{ 
	_barManager = barManager; 
	_barManager->SetContactFile(&_contactFile);
}

void GetDataFromFile::LoadStageSelectData()
{
	_contactFile.OpenFile("StageManager.txt");
	int stageValue = _contactFile.GetValue(true);
	std::string* stageFileNameArray = new std::string[stageValue];
	for (int i = 0;i < stageValue;i++)
	{
		stageFileNameArray[i] = _contactFile.GetString(false);
	}
	_contactFile.CloseFile();

	_barManager->CreateBarArray(stageValue);
	for (int i = 0;i < stageValue;i++)
	{
		_contactFile.OpenFile(stageFileNameArray[i]);

		std::string a = _contactFile.GetString(true);
		std::string b = _contactFile.GetString(false);
		int c = _contactFile.GetValue(false);
		std::string d = _contactFile.GetString(false);

		_barManager->SetBarStatu(i, a, b, c, d);
		_contactFile.CloseFile();
	}

	delete[] stageFileNameArray;
}

void GetDataFromFile::Release()
{
	_contactFile.Release();
}