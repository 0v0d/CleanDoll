#include "Bar.h"

void Bar::Initialize()
{
	_initialPos = Vector2(_screenPos.x + _space, _screenPos.y + _space / 2 + (_baseBarTexture->GetHeight() * _scale + _space) * _stageNumber);
	_screenEdge = CRectangle(_screenPos.x, _screenPos.y, _screenPos.x + _screenSize.x, _screenPos.y + _screenSize.y);

	_pos = _initialPos;
	_barHitBox = CRectangle(_pos.x, _pos.y, _pos.x + _baseBarTexture->GetWidth() * _scale, _pos.y + _baseBarTexture->GetHeight() * _scale);
	_maxMovePosY = (_space / 2 + _screenPos.y + (_baseBarTexture->GetHeight() * _scale + _space) * _stageValue) - _screenEdge.Bottom;

	_clear = _getCoin = false;
}

void Bar::SetScreenStatu(Vector2 screenPos, Vector2 screenSize) {
	_screenPos = screenPos;
	_screenSize = screenSize;
}

void Bar::SetStatu(float scale, float space) {
	_scale = scale;
	_space = space * _scale;
}

void Bar::SetData(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName)
{
	_stageNumber = stageNumber;
	_previewTexture.Load(previewTextureName.c_str());
	_barTexture.Load(barTextureName.c_str());
	_difficulty = difficulty;
	_stageDataTextName = stageDataTextName;
}

void Bar::ReLoad() {
	_pos = _initialPos;
}

void Bar::Move(float sliderValue)
{
	_pos.y = _initialPos.y - (_maxMovePosY * (sliderValue * 0.01f));
	_barHitBox = CRectangle(_pos.x, _pos.y, _pos.x + _baseBarTexture->GetWidth() * _scale, _pos.y + _baseBarTexture->GetHeight() * _scale);
}

CRectangle Bar::GetRenderRect(Vector2 pos, CTexture* texture) {
	if (CheckOnScreenTopLine(texture)) {
		return CRectangle(0, (_screenPos.y - pos.y) / _scale, texture->GetWidth(), texture->GetHeight());
	}

	if (pos.y < _screenPos.y + _screenSize.y && pos.y + texture->GetHeight() * _scale> _screenPos.y + _screenSize.y) {
		return CRectangle(0, 0, texture->GetWidth(), ((_screenPos.y + _screenSize.y) - pos.y) / _scale);
	}

	return CRectangle(0, 0, texture->GetWidth(), texture->GetHeight());
}

bool Bar::CheckOnScreenTopLine(CTexture* texture) {
	return _barHitBox.Top < _screenPos.y&& _barHitBox.Bottom > _screenPos.y;
}

bool Bar::IsRenderRange(CTexture* texture, Vector2 pos, float scale) {
	return CRectangle(pos.x, pos.y, pos.x + texture->GetWidth() * scale, pos.y + texture->GetHeight() * scale).CollisionRect(_screenEdge);
}

void Bar::Render()
{
	float posY = CheckOnScreenTopLine(_baseBarTexture) ? _screenPos.y : _pos.y;

	if (IsRenderRange(_baseBarTexture, _pos, _scale))_baseBarTexture->RenderScale(_pos.x, posY, _scale, GetRenderRect(_pos, _baseBarTexture));
	if (IsRenderRange(&_barTexture, _pos, _scale))_barTexture.RenderScale(_pos.x, posY, _scale, GetRenderRect(_pos, &_barTexture));

}

void Bar::Release()
{
	_previewTexture.Release();
	_barTexture.Release();
}