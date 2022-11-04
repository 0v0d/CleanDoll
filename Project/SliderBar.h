#pragma once
#include	"Mof.h"
class SliderBar
{
private:
	Vector2 _barSize;
	Vector2 _barPos;
	CRectangle	_barRect;

public:
	void SetBarStatu(Vector2 barSize, Vector2 barPos);
	bool IsCollisionBar(Mof::Vector2 mousepos) { return  _barRect.CollisionPoint(mousepos); }
	void Render();
};

