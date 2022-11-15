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
	SCREEN_TYPE	_typeName;
	CTexture* _backTexture;
	CRectangle _backRect;
public:
	void	SetTextureStatus(CTexture* backGroundTexture, SCREEN_TYPE typeName);
	void	Render();


};