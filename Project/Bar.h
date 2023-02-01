#pragma once
#include <string>
#include "Mof.h"

class Bar
{
private:
	CTexture* _barTexture;
	CRectangle _renderRect;
	CTexture _previewTexture;
	CTexture* _baseBarTexture;
	Vector2 _pos, _initialPos;
	float _space;
	CRectangle _barHitBox;
	float _scale;

	CRectangle _screenEdge;
	float _maxMovePosY;

	int _stageValue, _stageNumber;
	
	const int _maxDifficulty = 5;
	int _difficulty;
	CTexture** _difficultyTextureArray;
	float _difficultyScale;

	CTexture* _coinTexture;
	Vector2 _coinPos;
	float _coinScale;
	
	std::string _stageDataTextName;

	Vector2 _screenPos, _screenSize;

	bool _clear = false;
	bool _getCoin = false;

public:

	void Initialize();
	void ReLoad();
	void SetScreenStatu(Vector2 screenPos, Vector2 screenSize);
	void SetData(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName);
	void SetStageValue(int stageValue) { _stageValue = stageValue; }
	void SetBaseBarTexture(CTexture* texture) { _baseBarTexture = texture;}
	void SetCoinTexture(CTexture* texture) { _coinTexture = texture; CalcuCoinScale(); }
	void SetDifficulutyTexture(CTexture* texture);
	void SetBarTextureData(CTexture* texture, CRectangle renderRect);

	void SetScale(float scale);
	void Move(float sliderValue);

	void Clear() { _clear = true; }
	void GetCoin() { _getCoin = true; }

	void Render();
	void Release();

	bool CheckOnMouse(Vector2 mousePos) { return _barHitBox.CollisionPoint(mousePos); }
	bool IsClear() { return _clear; }
	bool IsGetCoin() { return _getCoin; }

	CTexture* GetPreviewTexture() { return &_previewTexture; }
	std::string GetStageDataTextName() { return _stageDataTextName; }

private:
	bool CheckOnScreenTopLine(float top,float bottom);
	CRectangle GetRenderRect(Vector2 pos, CRectangle rect, float scale);
	bool IsRenderRange(float sizeY, Vector2 pos, float scale);
	void CalcuCoinScale();
	void CalcuDifficultyScale();

	void RenderDifficulty();
	void RenderCoin();
};