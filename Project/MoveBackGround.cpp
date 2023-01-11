#include "MoveBackGround.h"

MoveBackGround::MoveBackGround() {
	_posX = 0;
}

void MoveBackGround::SetTexture(CTexture* texture) {
	_texture = texture; 

	_scale = g_pGraphics->GetTargetHeight() / _texture->GetHeight();
}

void MoveBackGround::Update() {
	_posX += _moveSpeed;
	if (_posX >= _texture->GetWidth() * _scale)_posX = 0;
}

void MoveBackGround::Render() {
	_texture->RenderScale(_posX, 0, _scale);
	_texture->RenderScale(_posX - _texture->GetWidth() * _scale, 0, _scale);
}