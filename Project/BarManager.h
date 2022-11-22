#pragma once

#include "ContactFile.h"
#include "Bar.h"
#include "Preview.h"
#include "Slider.h"

class BarManager
{
private:
	ContactFile* _contactFile;
	Bar* _barArray = nullptr;
	CTexture _baseTexture, _baseCleanBarTexture, _baseDirtyBarTexture,_BrackFrame;
	Vector2 _basePosition;
	int _stageValue, _currentStage;
	Preview _preview;
	float _baseBarScale;
	float _space;
	Slider _slider;
	CTexture _barTexture;
	CTexture _buttonTexture;

public:
	void Initialize();
	void ReLoad();
	void SetContactFile(ContactFile* contactFile) { _contactFile = contactFile; }
	void CreateBarArray(int stageValue);
	void SetBarStatu(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName);

	void Update();
	void Push(Vector2 mPos);
	void Pull(Vector2 mPos);
	void MoveBar(float moveValue);

	void StartStage(int barNumber);
	void StartNextStage();
	void SetPreview(int barNumber);
	void StageClear();

	void Render();
	void Release();

	Bar* GetBar(int barNumber) { return &_barArray[barNumber]; }
	int GetBarNumber(Vector2 mousePos);

private:
	void LoadTexture();
	void CalcuScale();
};