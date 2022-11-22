#pragma once
#include"Mof.h"

class StageSelectBackGround
{
private:
	CTexture* _backTexture;
	CRectangle _backRect;

	float     _ScrollY;
	float     _ScrollX;
	int      _ScrollSpeed;
public:
	void	Initialize();
	void    Update();
	void	SetTextureStatus(CTexture* backGroundTexture);
	void	Render();


};

