#include "Icon.h"

void const Icon::SetScale(float sizeX, float sizeY, float scale){
	if (scale != 0) {
		_scale = scale;
		return;
	}

	float size = sizeX != 0 ? _texture->GetWidth() : _texture->GetHeight();
	float targetSize = sizeX != 0 ? sizeX : sizeY;

	CalcuScale(size, targetSize);
}

void Icon::CalcuScale(float size, float targetSize) {
	_scale = targetSize / size;
}

void Icon::Render(){
	_texture->RenderScale(_pos.x, _pos.y, _scale);
}