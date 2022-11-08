

#include "Wall.h"

void Wall::SetWallPosition(Vector2 blockCenterPosition)
{
	if (_number == 2) {
		_wallPosition.x = blockCenterPosition.x - _wallTexture->GetWidth() * _scale / 2;
		_wallPosition.y = blockCenterPosition.y - _blockSizeY / 2 * _scale - _wallTexture->GetHeight() * _scale;
	}
	else {
		_wallPosition.x = blockCenterPosition.x - _wallTexture->GetWidth() * _scale;
		_wallPosition.y = blockCenterPosition.y - _wallTexture->GetHeight() * _scale;

		if (_number == 1)_wallPosition.x = blockCenterPosition.x;
	}
}

void Wall::SetWallObjectPosition(Vector2 blockCenterPosition)
{
	if (_number == 2) return;

	_wallObjectPosition.x = blockCenterPosition.x - _wallObjectTexture->GetWidth() * _scale / 2;
	_wallObjectPosition.y = blockCenterPosition.y + _blockSizeY * _scale / 2 - _wallObjectTexture->GetHeight() * _scale;

	_wallObjectRenderRect = CRectangle(0, 0, _wallObjectTexture->GetWidth(), _wallObjectTexture->GetHeight());

	if (_number != 1)return;

	auto tmp = _wallObjectRenderRect.Left;
	_wallObjectRenderRect.Left = _wallObjectRenderRect.Right;
	_wallObjectRenderRect.Right = tmp;
}

void Wall::Render()
{
	if (_wallTexture != nullptr)
	{
		_wallTexture->RenderScale(_wallPosition.x, _wallPosition.y, _scale);
	}

	if (_wallObjectTexture != nullptr)
	{
		_wallObjectTexture->RenderScale(_wallObjectPosition.x, _wallObjectPosition.y, _scale, _wallObjectRenderRect);
	}
}