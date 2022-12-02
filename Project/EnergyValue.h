#pragma once
#include "Mof.h"
class EnergyValue
{
private:
	CTexture _numberTexture;
	CTexture _onValueCircleTexture;
	CRectangle _renderRect;
	const int _numberValue = 10;
	float _onValueCircleScale;
	float _numberScale;
	Vector2 _onValueCirclePos;
	Vector2 _numberPos;
public:
	void Initialize();
	void CalcuRect(int currentEnergyValue);
	void Render();
	void Release();
	void SetScale(float scale) { _onValueCircleScale = scale; }
	void SetPosition(Vector2 vesselsCenterPosition);
private:
	void LoadTexture();
	void CalcuScale();
};