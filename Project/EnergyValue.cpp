#include "EnergyValue.h"

void EnergyValue::Initialize()
{
	LoadTexture();
}

void EnergyValue::CalcuScale()
{
	const float Adjustment = 1.5f;
	_numberScale *= Adjustment;
}
void EnergyValue::LoadTexture()
{
	_numberTexture.Load("num.png");
}

void EnergyValue::ReLoad()
{
	_slideInUI.SetPosition(_numberPos.x,&_numberPos.x,true);
}

void EnergyValue::Update()
{
	_slideInUI.Update();
}

void EnergyValue::SetPosition(Vector2 vesselsCenterPosition)
{
	_numberPos.x = vesselsCenterPosition.x - _numberTexture.GetWidth() / _numberValue * _numberScale / 2;
	_numberPos.y = vesselsCenterPosition.y - _numberTexture.GetHeight() * _numberScale / 2;
}

void EnergyValue::CalcuRect(int currentEnergyValue)
{
	_renderRect = CRectangle(_numberTexture.GetWidth() / _numberValue * (currentEnergyValue), 0,
		_numberTexture.GetWidth() / _numberValue * (currentEnergyValue + 1), _numberTexture.GetHeight());
}

void EnergyValue::Render()
{
	_numberTexture.RenderScale(_numberPos.x, _numberPos.y, _numberScale, _renderRect);
}

void EnergyValue::Release()
{
	_numberTexture.Release();
}