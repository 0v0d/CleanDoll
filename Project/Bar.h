#pragma once
#include <string>
#include "Mof.h"

class Bar
{
private:
	CTexture _barTexture, _previewTexture;
	CTexture* _baseBarTexture;
	Vector2 _pos, _initialPos;
	float _space;
	CRectangle _barHitBox;
	float _scale;

	CRectangle _screenEdge;
	float _maxMovePosY;

	int _stageValue, _stageNumber;
	int _difficulty;
	std::string _stageDataTextName;

	Vector2 _basePos, _baseSize;

	bool _clear;
public:
	void Initialize();
	void ReLoad();
	void SetStatu(float scale, float space);
	void SetBaseStatu(Vector2 basePos, Vector2 baseSize);
	void SetData(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName);
	void SetStageValue(int stageValue) { _stageValue = stageValue; }
	void SetBaseBarTexture(CTexture* texture) { _baseBarTexture = texture; }

	void Move(float sliderValue);
	void Clear() { _clear = true; }

	void Render();
	void Release();

	bool IsRenderRange() { return _barHitBox.CollisionRect(_screenEdge); }
	bool CheckOnMouse(Vector2 mousePos) { return _barHitBox.CollisionPoint(mousePos); }
	CTexture* GetPreviewTexture() { return &_previewTexture; }
	std::string GetStageDataTextName() { return _stageDataTextName; }
	bool IsClear() { return _clear; }

private:
	bool CheckOnTopLine();
	CRectangle GetRenderRect();
};

