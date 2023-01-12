#pragma once
#include "Mof.h"
class RemainingValue
{
private:
	CTexture* _numberTexture;
	int _currentRemaingValue;
	CRectangle _renderRect;
	const int _numberValue = 10;
	const float _numberScale = 0.05f;
	Vector2 _numberPos;
public:
	void SetStuts(CTexture* numberTexture);
	void SetPosition(Vector2 numberPosition);
	void Render();
	void SetValue(int remainingValue) { _currentRemaingValue = remainingValue; }
	void SupRemaingValue(){ _currentRemaingValue -= 1; }
	void CalucRect();
};