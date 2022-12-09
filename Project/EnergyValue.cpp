#include "EnergyValue.h"

void EnergyValue::Initialize()
{
	LoadTexture();
	CalcuScale();
}

void EnergyValue::CalcuScale()
{
	float sup = 0.8f;
	_numberScale = _onValueCircleTexture.GetHeight() * _onValueCircleScale / _numberTexture.GetHeight() * sup;
}

void EnergyValue::LoadTexture()
{
	_numberTexture.Load("num.png");
	_onValueCircleTexture.Load("EnergyVesselsOnValue.png");
}

void EnergyValue::SetPosition(Vector2 vesselsCenterPosition)
{
	const int space = 65;
	_onValueCirclePos.x = vesselsCenterPosition.x - _onValueCircleTexture.GetWidth() * _onValueCircleScale / 2;
	_onValueCirclePos.y = vesselsCenterPosition.y - _onValueCircleTexture.GetHeight() * _onValueCircleScale / 2 - space;
	_numberPos.x = vesselsCenterPosition.x - _numberTexture.GetWidth() / _numberValue * _numberScale / 2;
	_numberPos.y = _onValueCirclePos.y + _onValueCircleTexture.GetHeight() * _onValueCircleScale / 2 - _numberTexture.GetHeight() * _numberScale / 2;
}

void EnergyValue::CalcuRect(int currentEnergyValue)
{
	_renderRect = CRectangle(_numberTexture.GetWidth() / _numberValue * (currentEnergyValue), 0,
		_numberTexture.GetWidth() / _numberValue * (currentEnergyValue + 1), _numberTexture.GetHeight());
}

void EnergyValue::Render()
{
	_onValueCircleTexture.RenderScale(_onValueCirclePos.x, _onValueCirclePos.y, _onValueCircleScale);
	_numberTexture.RenderScale(_numberPos.x, _numberPos.y, _numberScale, _renderRect);
}

void EnergyValue::Release()
{
	_numberTexture.Release();
	_onValueCircleTexture.Release();

}