#pragma once
#include "Mof.h"
#include "SlideInUI.h"

class RemainingValue
{
private:
	CTexture* _numberTexture;
	int _currentRemaingValue;
	CRectangle _renderRect;
	const int _numberValue = 10;
	const float _numberScale = 0.05f;
	Vector2 _numberPos;
	SlideInUI _slideInUI;
public:
	void SetStuts(CTexture* numberTexture);
	void SetPosition(Vector2 numberPosition);
	void CalucRect();
	void ReLoad();
	void Update();
	void Render();

	void SetValue(int remainingValue) { _currentRemaingValue = remainingValue; }
	void SupRemaingValue() { _currentRemaingValue -= 1; }
};
