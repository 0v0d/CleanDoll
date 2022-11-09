#pragma once
#include "string"
#include"Mof.h"

class BackGround
{
private:
	CTexture* _backTexture;
	CRectangle _backRect;
public:
	void	SetTextureName(CTexture* textureName);
	void	Render();


};