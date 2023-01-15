#include "RemainingValue.h"

void RemainingValue::SetStuts(CTexture* numberTexture)
{
	_numberTexture = numberTexture;
}

void RemainingValue::SetPosition(Vector2 numberPosition)
{
	_numberPos.x = numberPosition.x;
	_numberPos.y = numberPosition.y;

	_slideInUI.SetStatu(_numberPos.x, &_numberPos.x,true);
}

void RemainingValue::CalucRect()
{
	_renderRect = CRectangle(_numberTexture->GetWidth() / _numberValue * _currentRemaingValue, 0,
		_numberTexture->GetWidth() / _numberValue * (_currentRemaingValue + 1), _numberTexture->GetHeight());
}

void RemainingValue::ReLoad()
{
	_slideInUI.Start();
}

void RemainingValue::Update()
{
	_slideInUI.Update();
}

void RemainingValue::Render()
{
	_numberTexture->RenderScale(_numberPos.x,_numberPos.y,_numberScale,_renderRect);
}
