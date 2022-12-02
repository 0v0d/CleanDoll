#pragma once
#include "Mof.h"
class RemainingValue
{
private:
	CTexture _numberTexture;
	CTexture _onValueCircleTexture;
	int _currentRemaingValue;
	CRectangle _renderRect;
	const int _numberValue = 10;
	float _onValueCircleScale;
	float _numberScale;
	Vector2 _onValueCirclePos;
	Vector2 _numberPos;
public:
	void Initialize();
	void Render();
	void Release();
	void SetMaxRemaingingValue(int maxRemainingValue) { _currentRemaingValue = maxRemainingValue; }
	void SupRemaingValue();
	void SetOnValueCircleScale(float scale) { _onValueCircleScale = scale; }
	void SetPosition(Vector2 basePosition);
	void CalucRect();
private:
	void LoadTexture();
	void CalucScale();
};