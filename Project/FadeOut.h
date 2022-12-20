#pragma once
#include	"Mof.h"

class FadeOut
{
private:
	int _alpha, _addAlphaValue;
	const int _maxAlpha = 255;
	bool _end;
public:
	FadeOut();
	void SetTime(int fadeInFrame);
	void Start();
	void Update();
	void Render();
	bool IsEnd() { return _end; }
};