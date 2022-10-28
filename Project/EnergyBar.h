#pragma once
#include	"Mof.h"
class EnergyBar
{
	CTexture* _barTexture;
	Vector2 _basePosition, _barPosition;
	int _barValue,_number;
	float _rotate, _scale;

	const float _doublePie = 3.14 * 2;

	MofU32* _renderColor;

public:
	void Initialize();

	void SetTexture(CTexture* barTexture) { _barTexture = barTexture; }
	void SetBasePosition(Vector2 basePosition) { _basePosition = basePosition; }
	void SetScale(float scale) { _scale = scale; }
	void SetBarValue(int barValue) { _barValue = barValue; }
	void SetNumber(int number) { _number = number; }

	void Update();
	void ChangeColor(MofU32* color) { _renderColor = color; }

	void Render();
	void UsedEnergyRender();
	void Release();
};