#pragma once
#include"Mof.h"
enum SCREEN_TYPE
{
	REPEATSCREEN,
	FULLSCREEN,
};
class BackGround
{
private:
	CTexture* _backTexture;
	CRectangle _backRect;
public:
	void	SetTextureName(CTexture* textureName);
	void	Render(SCREEN_TYPE typeName);


};