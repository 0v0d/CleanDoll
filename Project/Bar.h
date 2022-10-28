#pragma once
#include <string>
#include "Mof.h"

class Bar
{
private:
	CTexture _barTexture;
	const Vector2 _barSize = Vector2(700, 70);
	Vector2 _movePos;
	const int _space = 20;
	CRectangle _barHitBox;
	float _initializePosY;

	CTexture _previewTexture;

	Vector2 _screenPos;
	CRectangle _screenEdge;
	float _maxPos;

	int _stageValue;
	int _stageNumber;
	std::string _stageName;
	int _difficulty;
	std::string _stageDataTextName;
	const int _maxValue = 100;
public:
	void Initialize();
	void SetStatu(int stageNumber, std::string previewTextureName, std::string stageName, int difficulty, std::string stageDataTextName);
	void SetStageValue(int stageValue) { _stageValue = stageValue; }

	void Move(float moveValue);

	void Render();
	void Release();

	bool IsRenderRange() { return _barHitBox.CollisionRect(_screenEdge); }
	bool CheckOnMouse(Vector2 mousePos) { return _barHitBox.CollisionPoint(mousePos); }
	int GetStageNumber() { return _stageNumber; }
	CTexture* GetPreviewTexture() { return &_previewTexture; }
	std::string GetStageDataTextName() { return _stageDataTextName; }
};

