#pragma once
#include "Mof.h"
class EnergyValue
{
private:
	CTexture _numberTexture;
	CRectangle _renderRect;
	//const int _numberValue = 10;
	const int _numberValue = 9;
	float _numberScale;
	Vector2 _numberPos;

public:
	void Initialize();
	void CalcuRect(int currentEnergyValue);
	void Render();
	void Release();
	void SetScale(float scale) { _numberScale = scale; }
	void SetPosition(Vector2 vesselsCenterPosition);
private:
	void LoadTexture();
	void CalcuScale();
};