#pragma once
#include "Mof.h"
class RemainingValue
{
private:
	CTexture _numberTexture;
	int _currentRemaingValue;
	CRectangle _renderRect;
	const int _numberValue = 10;
	float _numberScale;
	Vector2 _onValueCirclePos;
	Vector2 _numberPos;
public:
	void Initialize();
	void Render();
	void Release();
	void SetValue(int remainingValue) { _currentRemaingValue = remainingValue; }
	void SupRemaingValue();
	void SetPosition(Vector2 numPosition);
	void CalucRect();
private:
	void LoadTexture();
	void CalucScale();
};