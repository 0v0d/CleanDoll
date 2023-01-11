#include "RemainingValue.h"

void RemainingValue::CalucScale()
{
	_numberScale = 0.05f;
}

void RemainingValue::SetPosition(Vector2 numPosition)
{
	CalucScale();
	_numberPos.x = numPosition.x;
	_numberPos.y = numPosition.y;
}

void RemainingValue::Initialize()
{
	LoadTexture();
}

void RemainingValue::LoadTexture()
{
	_numberTexture.Load("num.png");
}

void RemainingValue::CalucRect()
{
	_renderRect = CRectangle(_numberTexture.GetWidth() / _numberValue * _currentRemaingValue, 0,
		_numberTexture.GetWidth() / _numberValue * (_currentRemaingValue + 1), _numberTexture.GetHeight());
}

void RemainingValue::Render()
{
	_numberTexture.RenderScale(_numberPos.x,_numberPos.y,_numberScale,_renderRect);
}

void RemainingValue::Release()
{
	_numberTexture.Release();
}

void RemainingValue::SupRemaingValue()
{
	_currentRemaingValue -= 1;
}


