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
	CTexture** _difficultyTextureArray;
	Vector2 _difficultyPos;
	float _difficultyScale;

	CTexture* _coinTexture;
	float _coinScale;
	
	std::string _stageDataTextName;

	Vector2 _screenPos, _screenSize;

	bool _clear, _getCoin;	

public:

	void Initialize();
	void ReLoad();
	void SetStatu(float scale, float space);
	void SetScreenStatu(Vector2 screenPos, Vector2 screenSize);
	void SetData(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName);
	void SetStageValue(int stageValue) { _stageValue = stageValue; }
	void SetBaseBarTexture(CTexture* texture) { _baseBarTexture = texture; }
	void SetCoinTexture(CTexture* texture) { _coinTexture = texture; }

	void Move(float sliderValue);
	void Clear() { _clear = true; }
	void GetCoin() { _getCoin = true; }

	void Render();
	void Release();

	bool CheckOnMouse(Vector2 mousePos) { return _barHitBox.CollisionPoint(mousePos); }
	CTexture* GetPreviewTexture() { return &_previewTexture; }
	std::string GetStageDataTextName() { return _stageDataTextName; }
	bool IsClear() { return _clear; }
	bool IsGetCoin() { return _getCoin; }
	void SetDifficulutyTexture(CTexture* texture);

	void ScaleUp(float scale) { _scale = scale; }

private:
	bool CheckOnScreenTopLine(float top,float bottom);
	CRectangle GetRenderRect(Vector2, CTexture*,float scale);
	bool IsRenderRange(CTexture*, Vector2, float scale);
	
};
