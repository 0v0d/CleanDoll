#pragma once
#include	"Mof.h"
class MoveBackGround
{
	CTexture* _texture;
	const int _moveSpeed = 3;
	float _posX;
	float _scale;

public:
	MoveBackGround();
	void SetTexture(CTexture* texture);
	void Update();
	void Render();
};