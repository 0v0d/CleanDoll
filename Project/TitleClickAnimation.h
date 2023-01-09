#pragma once
#include	"Mof.h"
class TitleClickAnimation
{
	CTexture _texture;
	float _time;
	uint8_t _alpha;
	const float _alphaIncrease = 0.008f;
	const uint8_t _maxAlpha = 255;
	//ç≈í·Ç≈Ç‡ï`âÊÇ≥ÇπÇÈ%
	const float miniAlphaPercentage = 0.3f;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();

private:
	void LoadTexture();
	void CalcAlpha();
};