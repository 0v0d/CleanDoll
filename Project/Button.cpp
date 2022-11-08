#include "Button.h"

void Button::SetStatu(Vector2 position, CTexture* texture)
{
	_position = position;
	_texture = texture;
	_size = Vector2(_texture->GetWidth(), _texture->GetHeight());
	_button = CRectangle(_position.x, _position.y, _position.x + _size.x, _position.y + _size.y);
}


void Button::Render()
{
	CGraphicsUtilities::RenderFillRect(_button, MOF_COLOR_WHITE);
	_texture->Render(_position.x, _position.y);
}