#include "Bar.h"

void Bar::Initialize()
{
	_initialPos = Vector2(_screenPos.x + _space, _screenPos.y + _space / 2 + (_baseBarTexture->GetHeight() * _scale + _space) * _stageNumber);
	_screenEdge = CRectangle(_screenPos.x, _screenPos.y, _screenPos.x + _screenSize.x, _screenPos.y + _screenSize.y);

	_pos = _initialPos;
	_barHitBox = CRectangle(_pos.x, _pos.y, _pos.x + _baseBarTexture->GetWidth() * _scale, _pos.y + _baseBarTexture->GetHeight() * _scale);
	_maxMovePosY = (_space / 2 + _screenPos.y + (_baseBarTexture->GetHeight() * _scale + _space) * _stageValue) - _screenEdge.Bottom;
	_difficultyScale = _barHitBox.GetHeight() / 2 / _difficultyTextureArray[0]->GetHeight() - 0.1f;
	_coinScale = _barHitBox.GetHeight() / _coinTexture->GetHeight() - 0.12f;
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

	_difficultyTextureArray = new CTexture * [_difficulty];
}

void Bar::SetDifficulutyTexture(CTexture* texture)
{
	for (int i = 0; i < _difficulty; i++)
	{
		_difficultyTextureArray[i] = texture;
	}
}

void Bar::ReLoad() {
	_pos = _initialPos;
}

void Bar::Move(float sliderValue)
{
	_pos.y = _initialPos.y - (_maxMovePosY * (sliderValue * 0.01f));
	_barHitBox = CRectangle(_pos.x, _pos.y, _pos.x + _baseBarTexture->GetWidth() * _scale, _pos.y + _baseBarTexture->GetHeight() * _scale);
}

CRectangle Bar::GetRenderRect(Vector2 pos, CTexture* texture, float scale) {
	if (CheckOnScreenTopLine(pos.y, pos.y + texture->GetHeight())) {
		return CRectangle(0, (_screenPos.y - pos.y) / scale, texture->GetWidth(), texture->GetHeight());
	}

	if (pos.y < _screenPos.y + _screenSize.y && pos.y + texture->GetHeight() * scale> _screenPos.y + _screenSize.y) {
		return CRectangle(0, 0, texture->GetWidth(), ((_screenPos.y + _screenSize.y) - pos.y) / scale);
	}

	return CRectangle(0, 0, texture->GetWidth(), texture->GetHeight());
}

bool Bar::CheckOnScreenTopLine(float top, float bottom) {
	return top < _screenPos.y&& bottom > _screenPos.y;
}

bool Bar::IsRenderRange(CTexture* texture, const Vector2 pos, float scale) {
	return CRectangle(pos.x, pos.y, pos.x + texture->GetWidth() * scale, pos.y + texture->GetHeight() * scale).CollisionRect(_screenEdge);
}

void Bar::Render()
{
	float posY = CheckOnScreenTopLine(_pos.y, _pos.y + _baseBarTexture->GetHeight()) ? _screenPos.y : _pos.y;

	if (IsRenderRange(_baseBarTexture, _pos, _scale))_baseBarTexture->RenderScale(_pos.x, posY, _scale, GetRenderRect(_pos, _baseBarTexture, _scale));
	if (IsRenderRange(&_barTexture, _pos, _scale))_barTexture.RenderScale(_pos.x, posY, _scale, GetRenderRect(_pos, &_barTexture, _scale));



	for (int i = 0; i < _difficulty; i++) {
		const auto space = Vector2(113, 12);
		_difficultyPos = Vector2(_pos.x + space.x, _pos.y + _barTexture.GetHeight() / 2 - space.y);
		posY = _difficultyPos.y < _screenPos.y&& _pos.y + _difficultyPos.y + _difficultyTextureArray[i]->GetHeight() * _difficultyScale > _screenPos.y ?
			_screenPos.y : _difficultyPos.y;

		if (IsRenderRange(_difficultyTextureArray[i], Vector2(_difficultyPos.x, _difficultyPos.y), _difficultyScale)){
			constexpr auto interval = 5;
			_difficultyTextureArray[i]->RenderScale
			(_difficultyPos.x + (_difficultyTextureArray[i]->GetWidth() * _difficultyScale + interval) * i, posY, _difficultyScale,
				GetRenderRect(_difficultyPos, _difficultyTextureArray[i], _difficultyScale));
		}
			
	}
	if (_getCoin) {
		const auto space = Vector2(10, 20);
		_coinPos = Vector2(_barHitBox.Right - _coinTexture->GetWidth() * _coinScale - space.x, _pos.y + space.y);
		posY = CheckOnScreenTopLine(_coinPos.y, _coinPos.y + _coinTexture->GetHeight()) ? _screenPos.y : _coinPos.y;

		if (IsRenderRange(_coinTexture, Vector2(_coinPos.x, _coinPos.y), _coinScale)) {
			_coinTexture->RenderScale(_coinPos.x, posY, _coinScale,
				GetRenderRect(_coinPos, _coinTexture, _coinScale));
		}
	}
}

void Bar::Release()
{
	_previewTexture.Release();
	_barTexture.Release();

	delete[] _difficultyTextureArray;
}