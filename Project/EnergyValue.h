#pragma once
#include "Mof.h"
#include "SlideInUI.h"

class EnergyValue
{
private:
	CTexture _numberTexture;
	CRectangle _renderRect;
	const int _numberValue = 10;
	float _numberScale;
	Vector2 _numberPos;
	SlideInUI _slideInUI;
public:
	void Initialize();
	void SetScale(float scale) { _numberScale = scale; }
	void SetPosition(Vector2 vesselsCenterPosition);
	void ReLoad();

	void Update();
	void CalcuRect(int currentEnergyValue);

	void Render();
	void Release();

private:
	void LoadTexture();
};
