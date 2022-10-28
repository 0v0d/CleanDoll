#include "Object.h"

void Object::SetBlockSize(float blockSizeX, float blockSizeY) {
	_blockSizeX = blockSizeX;
	_blockSizeY = blockSizeY;
}

void Object::SetPosition(Vector2 blockCenterPosition) {
	_objectRenderRect = CRectangle(0, 0, _objectTexture->GetWidth(), _objectTexture->GetHeight());

	_objectPosition.x = blockCenterPosition.x - _blockSizeX * _scale / 2;
	_objectPosition.y = blockCenterPosition.y + _blockSizeY * _scale / 2 - _objectTexture->GetHeight() * _scale;
}

void Object::Swap() {
	auto tmp = _objectRenderRect.Left;
	_objectRenderRect.Left = _objectRenderRect.Right;
	_objectRenderRect.Right = tmp;

	_objectPosition.x += _blockSizeX - _objectTexture->GetWidth();
}

void Object::Render() {
	_objectTexture->RenderScale(_objectPosition.x,_objectPosition.y, _scale, _objectRenderRect);
}

void Object::Release() {

}