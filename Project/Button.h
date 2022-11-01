#pragma once
#include	"Mof.h"
class Button
{
	Vector2 _position, _size;
	CRectangle _button;
public:
	void SetStatu(Vector2 position, Vector2 size);
	void Initialzie();
	bool CheckPushButton(Vector2 mousePos) { return _button.CollisionPoint(mousePos); }
	void Render();
	void Release();
};