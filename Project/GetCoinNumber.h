#pragma once
#include	"Mof.h"

class GetCoinNumber
{
private:
	CTexture coinnumberTexture;
	Vector2  numberPos;

	int		CoinNumberValue;
	float	renderSizeX;
	float	_scale=5;
	CRectangle	renderRect;
public:
	void Initialize();
	void LoadTextrue();
	void SetPosition();
	void SetCoinNumberValue(int value);

	void Render();
	void Release();

private:
	void ChangeCoinNumber(int coinnumbre);
};

