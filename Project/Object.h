#pragma once
#include	"Mof.h"
class Object
{
private:
	CTexture* _objectTexture = nullptr;
	Vector2 _objectPosition;
	float _blockSizeX, _blockSizeY;
	float _scale;
	CRectangle _objectRenderRect;
public:
	Object(CTexture* objectTexture) { _objectTexture = objectTexture; }
	void SetBlockSize(float blockSizeX, float blockSizeY);
	void CalcuScale(float blockSizeX) { _scale = blockSizeX / _objectTexture->GetWidth(); }
	void SetPosition(Vector2 blockCenterPosition);
	void Swap();
	void Render();
	void Release();
};