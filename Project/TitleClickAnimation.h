#pragma once
#include	"Mof.h"
class TitleClickAnimation
{
	CTexture _texture;
	float _time;
	uint8_t _alpha;
	const float _alphaIncrease = 0.003f;
	const uint8_t _maxAlpha = 255;

public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();

private:
	void LoadTexture();
	int CalcAlpha(float time);
};