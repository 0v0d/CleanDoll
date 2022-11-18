#pragma once
#include <string>
#include "ContactFile.h"
#include "Bar.h"
#include "Preview.h"

class BarManager
{
private:
	ContactFile* _contactFile;
	Bar* _barArray = nullptr;
	int _stageValue, _currentStage;
	Preview _preview;
public:
	void Initialize();
	void SetContactFile(ContactFile* contactFile) { _contactFile = contactFile; }
	void CreateBarArray(int stageValue);
	void SetBarStatu(int stageNumber, std::string previewTextureName, std::string stageName, int difficulty, std::string stageDataTextName);
	void Update();
	void PushBar(Vector2 mPos);
	void PickStage(int bernumber);
	void MoveBar(float moveValue);
	void StartNextStage();
	void Render();
	void Release();
	Bar* GetBar(int barNumber) { return &_barArray[barNumber]; }
	int GetPushBarNumber(Vector2 mousePos);
};