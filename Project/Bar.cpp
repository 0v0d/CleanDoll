#include "Bar.h"

void Bar::Initialize()
{
	_initialPos = Vector2(_basePos.x + _space, _basePos.y + _space / 2 + (_baseBarTexture->GetHeight() * _scale + _space) * _stageNumber);
	_screenEdge = CRectangle(_basePos.x, _basePos.y, _basePos.x + _baseSize.x, _basePos.y + _baseSize.y);

	_pos = _initialPos;
	_barHitBox = CRectangle(_pos.x, _pos.y, _pos.x + _baseBarTexture->GetWidth() * _scale, _pos.y + _baseBarTexture->GetHeight() * _scale);
	_maxMovePosY = (_space / 2 + _basePos.y + (_baseBarTexture->GetHeight() * _scale + _space) * _stageValue) - _screenEdge.Bottom;
}

void Bar::SetBaseStatu(Vector2 basePos, Vector2 baseSize) {
	_basePos = basePos;
	_baseSize = baseSize;
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

CRectangle Bar::GetRenderRect() {
	if (_barHitBox.Top < _basePos.y && _barHitBox.Bottom > _basePos.y) {
		return CRectangle(0, (_basePos.y - _barHitBox.Top) / _scale, _baseBarTexture->GetWidth(), _baseBarTexture->GetHeight());
	}

	if (_barHitBox.Top < _basePos.y + _baseSize.y && _barHitBox.Bottom > _basePos.y + _baseSize.y) {
		return CRectangle(0, 0, _baseBarTexture->GetWidth(), ((_basePos.y + _baseSize.y) - _barHitBox.Top) / _scale);
	}

	return CRectangle(0, 0, _baseBarTexture->GetWidth(), _baseBarTexture->GetHeight());
}

void Bar::Render()
{
	if (IsRenderRange())
	{
		if (_barHitBox.Top < _basePos.y && _barHitBox.Bottom > _basePos.y)
			_baseBarTexture->RenderScale(_pos.x, _basePos.y, _scale, GetRenderRect());
		else _baseBarTexture->RenderScale(_pos.x, _pos.y, _scale, GetRenderRect());
		_barTexture.RenderScale(_pos.x, _pos.y, _scale, GetRenderRect());
	}
}

void Bar::Release()
{
	_previewTexture.Release();
	_barTexture.Release();
}