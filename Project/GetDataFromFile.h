#pragma once
#include	"BarManager.h"
#include	"ContactFile.h"

class GetDataFromFile
{
private:
	ContactFile _contactFile;
	BarManager* _barManager;
public:
	void Initialize();
	void SetBarManager(BarManager* barManager);
	void LoadStageSelectData();
	void Release();
	ContactFile* GetContactFile() { return &_contactFile; }
};