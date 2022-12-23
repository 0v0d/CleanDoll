#pragma once
#include "Bar.h"
#include "Preview.h"
#include "Slider.h"

class BarManager
{
private:

	Bar* _barArray = nullptr;
	CTexture _baseTexture, _frameTexture;
	CTexture _baseCleanBarTexture, _baseDirtyBarTexture;
	Vector2 _basePosition;
	int _stageValue, _currentStage;

	float _baseBarScale;
	float _space;
	Slider _slider;
	CTexture _barTexture,_buttonTexture;

	CTexture _difficultyTexture;
	
	
	
	Vector2 _mousePos;

public:
	void Initialize();
	void ReLoad();
	void CreateBarArray(int stageValue);
	void SetBarStatu(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName);

	void Update();
	void SetMousePos(Vector2 mousePos) { _mousePos = mousePos; }
	void Push();
	void Pull();
	void MoveBar(float moveValue);

	//•K—v‚È‚¢
	void StartStage(int barNumber);
	void StartNextStage();
	void StageClear();

	void Render();
	void Release();

	Bar* GetBar(int barNumber);
	int GetBarNumber(Vector2 mousePos);
	int GetCurrentStageNumber() { return _currentStage; }
	float GetBaseSizeY() { return _baseTexture.GetHeight(); }

private:
	void LoadTexture();
	void CalcuScale();
};