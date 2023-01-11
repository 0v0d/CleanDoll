#pragma once
#include	"Mof.h"
class FadeIn
{
private:
	int _alpha, _subAlphaValue;
	const int _maxAlpha = 255;
	bool _end;
public:
	FadeIn();
	void SetTime(int fadeInFrame);
	void Start();
	void Update();
	void Render();
	bool IsEnd() { return _end; }
};