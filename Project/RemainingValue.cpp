#include "RemainingValue.h"

void RemainingValue::CalucScale()
{
	float sup = 0.6f;
	_numberScale = _onValueCircleTexture.GetHeight() * _onValueCircleScale / _numberTexture.GetHeight() * sup;
}

void RemainingValue::SetPosition(Vector2 basePosition)
{
	
	_onValueCirclePos = basePosition;
	_numberPos.x = _onValueCirclePos.x + _onValueCircleTexture.GetWidth() - _numberTexture.GetWidth() * _numberScale;
	_numberPos.y = 690;

}

void RemainingValue::Initialize()
{
	LoadTexture();
	CalucScale();
}

void RemainingValue::LoadTexture()
{
	_numberTexture.Load("num.png");
	_onValueCircleTexture.Load("onValueCircle.png");
}

void RemainingValue::CalucRect()
{
	_renderRect = CRectangle(_numberTexture.GetWidth() / _numberValue * _currentRemaingValue, 0,
		_numberTexture.GetWidth() / _numberValue * (_currentRemaingValue + 1), _numberTexture.GetHeight());
}

void RemainingValue::Render()
{
	_onValueCircleTexture.RenderScale(_onValueCirclePos.x, _onValueCirclePos.y,_onValueCircleScale);
	_numberTexture.RenderScale(_numberPos.x,_numberPos.y,_numberScale,_renderRect);
	//150,690
}

void RemainingValue::Release()
{
	_numberTexture.Release();
	_onValueCircleTexture.Release();
}

void RemainingValue::SupRemaingValue()
{
	_currentRemaingValue -= 1;
}


