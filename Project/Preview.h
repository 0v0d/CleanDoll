#pragma once
#include	"Mof.h"

class Preview
{
private:
	CTexture _baseTexture;
	CTexture* _previewTexture;
	Vector2 _previewPosition, _basePos;
	float _baseScale, _previewScale;
public:
	void Initialize();
	void CalcuBaseScale(float BarBaseTextureHeight);
	void CalcuBasePos(float space);
	void SetPreviewTexture(CTexture* previewTexture);

	void Render();
	void Release();
private:
	void LoadTexture();
	void SetPosistion();
	void CalcuPreviewScale();
};