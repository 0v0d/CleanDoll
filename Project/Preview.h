#pragma once
#include	"Mof.h"
class Preview
{
	CTexture* _previewTexture;
	Vector2 _previewPosition;
	const int _space = 50;
public:
	void SetPreviewTexture(CTexture* previewTexture);
	void Render();
private:
	void SetPosistion();
};