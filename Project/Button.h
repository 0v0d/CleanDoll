#pragma once
#include	"Mof.h"

class Button
{
private:
	Vector2 _position, _size;
	CRectangle _button;
	CTexture _texture;
public:
	void SetStatu(Vector2 position, Vector2 size);
	bool CheckOnButton(Vector2 mousePos) { return _button.CollisionPoint(mousePos); }
	void Render();
};