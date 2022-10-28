#pragma once
#include	"Mof.h"
class Wall
{
	CTexture* _wallTexture = nullptr;
	CTexture* _wallObjectTexture = nullptr;
	int _number;

	float _blockSizeY;
	float _scale;

	Vector2 _wallPosition, _wallObjectPosition;
	CRectangle _wallObjectRenderRect;

public:
	void SetBlockSize(float blockSizeY) { _blockSizeY = blockSizeY; }
	void SetNumber(int number) { _number = number; }
	void SetWallTexture(CTexture* wallTexture) { _wallTexture = wallTexture; }
	void SetScale(float scale) { _scale = scale; }
	void SetWallPosition(Vector2 blockCenterPosition);
	void SetWallObjectTexture(CTexture* wallObjectTexture) { _wallObjectTexture = wallObjectTexture; }
	void SetWallObjectPosition(Vector2 blockCenterPosition);
	void Render();
};