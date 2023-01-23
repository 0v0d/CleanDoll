#include "Bar.h"

void Bar::Initialize()
{
	const int space = 60;
	_initialPos = Vector2(_screenPos.x + space, _screenPos.y + space + (_baseBarTexture->GetHeight() * _scale + space) * _stageNumber);
	_screenEdge = CRectangle(_screenPos.x, _screenPos.y, _screenPos.x + _screenSize.x, _screenPos.y + _screenSize.y);

	_pos = _initialPos;
	_barHitBox = CRectangle(_pos.x, _pos.y, _pos.x + _baseBarTexture->GetWidth() * _scale, _pos.y + _baseBarTexture->GetHeight() * _scale);
	_maxMovePosY = (space / 2 + _screenPos.y + (_baseBarTexture->GetHeight() * _scale + space) * _stageValue) - _screenEdge.Bottom;
	CalcuDifficultyScale();

	_clear = _getCoin = false;
}

void Bar::SetScreenStatu(Vector2 screenPos, Vector2 screenSize) {
	_screenPos = screenPos;
	_screenSize = screenSize;
}

void Bar::SetScale(float scale) {
	_scale = scale;
	CalcuDifficultyScale();
	CalcuCoinScale();
}

void Bar::SetData(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName)
{
	_stageNumber = stageNumber;
	_previewTexture.Load(previewTextureName.c_str());
	_difficulty = difficulty;
	_stageDataTextName = stageDataTextName;

	_difficultyTextureArray = new CTexture * [_maxDifficulty];
}

void Bar::SetDifficulutyTexture(CTexture* texture)
{
	for (int i = 0; i < _maxDifficulty; i++)
	{
		_difficultyTextureArray[i] = texture;
	}
}

void Bar::SetBarTextureData(CTexture* texture, CRectangle renderRect) {
	_barTexture = texture;
	_renderRect = renderRect;
}

void Bar::CalcuDifficultyScale() { 
	_difficultyScale = _baseBarTexture->GetHeight() * _scale / 2 / _difficultyTextureArray[0]->GetHeight() * 0.7f; 
}

void Bar::CalcuCoinScale() {
	_coinScale = _baseBarTexture->GetHeight() * _scale / _coinTexture->GetHeight() * 0.7f;
}

void Bar::ReLoad() {
	_pos = _initialPos;
}

void Bar::Move(float sliderValue)
{
	_pos.y = _initialPos.y - (_maxMovePosY * (sliderValue * 0.01f));
	_barHitBox = CRectangle(_pos.x, _pos.y, _pos.x + _baseBarTexture->GetWidth() * _scale, _pos.y + _baseBarTexture->GetHeight() * _scale);
}


CRectangle Bar::GetRenderRect(Vector2 pos, CRectangle rect,float scale) {
	Vector2 size = Vector2((rect.Right - rect.Left) * scale, (rect.Bottom - rect.Top) * scale);

	if (CheckOnScreenTopLine(pos.y, pos.y + size.y)) {
		return CRectangle(rect.Left, (_screenPos.y - pos.y) / scale+rect.Top, rect.Right, rect.Bottom);
	}

	if (pos.y < _screenPos.y + _screenSize.y && pos.y + size.y > _screenPos.y + _screenSize.y) {
		return CRectangle(rect.Left, rect.Top, rect.Right, ((_screenPos.y + _screenSize.y) - pos.y) / scale + rect.Top);
	}

	return rect;
}

bool Bar::CheckOnScreenTopLine(float top, float bottom) {
	return top < _screenPos.y && bottom > _screenPos.y;
}

bool Bar::IsRenderRange(float sizeY, const Vector2 pos, float scale) {
	return pos.y + sizeY * scale > _screenEdge.Top && pos.y < _screenEdge.Bottom;
}

void Bar::Render()
{
	float posY = CheckOnScreenTopLine(_pos.y, _pos.y + _baseBarTexture->GetHeight()) ? _screenPos.y : _pos.y;

	if (IsRenderRange(_baseBarTexture->GetHeight(), _pos, _scale))_baseBarTexture->RenderScale(_pos.x, posY, _scale, GetRenderRect(_pos, CRectangle(0, 0, _baseBarTexture->GetWidth(), _baseBarTexture->GetHeight()), _scale));
	if (IsRenderRange(_barTexture->GetHeight()/ _stageValue, _pos, _scale))_barTexture->RenderScale(_pos.x, posY, _scale, GetRenderRect(_pos, _renderRect, _scale));

	RenderDifficulty();
	RenderCoin();
}

void Bar::RenderDifficulty() {
	int space = 30;
	space *= _scale;
	float baseY = _pos.y + _baseBarTexture->GetHeight() / 2 * _scale + space;
	float posY = CheckOnScreenTopLine(baseY,baseY+ _difficultyTextureArray[0]->GetHeight()*_difficultyScale) ? _screenPos.y : baseY;
	Vector2 baseDifficultyPos = Vector2(_pos.x + space + 450 * _scale, baseY);
	
	if (IsRenderRange(_difficultyTextureArray[0]->GetHeight(), baseDifficultyPos, _difficultyScale)) {
		for (int i = 0; i < _maxDifficulty; i++) {

			float renderFactor = i < _difficulty ? _difficultyTextureArray[i]->GetWidth() / 2 : 0;
			CRectangle renderRect = CRectangle(renderFactor, 0, renderFactor + _difficultyTextureArray[i]->GetWidth() / 2, _difficultyTextureArray[i]->GetHeight());
			Vector2 diffPos = Vector2(baseDifficultyPos.x + (_difficultyTextureArray[i]->GetWidth() / 2 * _difficultyScale + space) * i, baseY);
			_difficultyTextureArray[i]->RenderScale(diffPos.x, posY, _difficultyScale, GetRenderRect(diffPos, renderRect, _difficultyScale));
		}
	}
}

void Bar::RenderCoin() {
	int space = 50;
	space *= _scale;
	_coinPos = Vector2(_pos.x + _baseBarTexture->GetWidth() * _scale - _coinTexture->GetWidth() / 2 * _coinScale - space, _pos.y + _baseBarTexture->GetHeight() / 2 * _scale - _coinTexture->GetHeight() / 2 * _coinScale);

	if (!IsRenderRange(_coinTexture->GetHeight(), _coinPos, _coinScale)) return;

	float posY = CheckOnScreenTopLine(_coinPos.y, _coinPos.y + _coinTexture->GetHeight() * _coinScale) ? _screenPos.y : _coinPos.y;
	
	float renderFactor = _getCoin ? _coinTexture->GetWidth() / 2 : 0;
	CRectangle renderRect = CRectangle(renderFactor, 0, renderFactor + _coinTexture->GetWidth() / 2, _coinTexture->GetHeight());

	_coinTexture->RenderScale(_coinPos.x, posY, _coinScale,GetRenderRect(_coinPos, renderRect, _coinScale));
}

void Bar::Release()
{
	_previewTexture.Release();
	
	delete[] _difficultyTextureArray;
}