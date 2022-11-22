#pragma once
#include"Mof.h"

class StageSelectBackGround
{
private:
	CTexture* _backTexture;
	CRectangle _backRect;

	float     _scrollY;
	float     _scrollX;
	const int _scrollSpeed = 1;
public:
	void	Initialize();
	void    Update();
	void	SetTextureStatus(CTexture* backGroundTexture);
	void	Render();


};

