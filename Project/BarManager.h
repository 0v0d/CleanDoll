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
	CTexture _baseTexture, _baseCleanBarTexture, _baseDirtyBarTexture;
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
	void PickStage(Vector2 mPos);
	void MoveBar(float moveValue);
	void StartNextStage();

	void Render();
	void Release();
	Bar* GetBar(int barNumber) { return &_barArray[barNumber]; }

private:
	void LoadTexture();
	void CalcuScale();
};