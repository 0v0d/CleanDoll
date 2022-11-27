#pragma once
#include	"Mof.h"
class Icon
{
	CTexture* _texture;
	Vector2 _pos;
	float _scale = 1;
public:
	void SetTexture(CTexture* texture) { _texture = texture; }
	void SetPos(Vector2 pos) { _pos = pos; }
	void const SetScale(float* sizeX, float* sizeY, float* scale);

	void Render();

private:
	void CalcuScale(float size, float targetSize);
};