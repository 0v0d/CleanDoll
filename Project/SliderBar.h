#pragma once
#pragma once
#include	"Mof.h"
class SliderBar
{
private:
	Vector2 _barSize;
	Vector2 _barPos;
	CRectangle	_barRect;
	CRectangle	_renderRect;
	CTexture* _barTexture;
public:
	void SetBarStatu(CTexture* barTexture, Vector2 barPos);
	bool IsCollisionBar(Vector2 mousepos) { return  _barRect.CollisionPoint(mousepos); }
	void Render();
};

