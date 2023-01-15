#pragma once
#include "Mof.h"
#include "SlideInUI.h"
class Number
{
private:
	SlideInUI _slideInUI;
	CTexture* _numberTexture;
	int _currentValue;
	CRectangle _renderRect;
	int _numberMaxValue;
	float _numberScale;
	Vector2 _numberPos;
public:
	void SetStats(CTexture* numberTexture, float scale, int  numValueIndex);
	void SetPosition(Vector2 numberPosition);
	void SetMove(bool left);
	void ReLoad();
	void Update();
	void Render();

	void SetValue(int value) { _currentValue = value; }
	void SupRemaingValue() { _currentValue -= 1; }
private:
	CRectangle CalcuRect();
};

