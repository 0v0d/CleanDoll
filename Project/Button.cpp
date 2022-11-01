#include "Button.h"

void Button::SetStatu(Vector2 position, Vector2 size)
{
	_position = position;
	_size = size;
	_button = CRectangle(_position.x, _position.y, _position.x + _size.x, _position.y + _size.y);
}

void Button::Initialzie()
{

}

void Button::Render()
{
	CGraphicsUtilities::RenderFillRect(_button, MOF_COLOR_GREEN);
}

void Button::Release()
{

}