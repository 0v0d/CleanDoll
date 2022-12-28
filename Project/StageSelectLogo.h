#pragma once
#include "Mof.h"
class StageSelectLogo
{
private:
	CTexture	StSelectLogoTexture;
	float		posX,posY;
	bool		SlidIn;
	int			Alpha;
public:
	void Initialize();
	void ReLoad();
	void Load();
	void Update();
	void Render();
	void Release();

};

