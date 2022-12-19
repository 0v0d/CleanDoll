#pragma once
#include	"Mof.h"

class FadeIn
{
private:
	int		Alpha;
	bool	fadeIn;
public:
	void Initialize();
	void Update();
	void Render();
	void GetIn() { fadeIn = true; }
	bool IsIn() { return fadeIn; }
};