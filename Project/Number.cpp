#include "Number.h"

void Number::SetStats(CTexture* numberTexture, float scale, int numValueIndex)
{
	_numberTexture = numberTexture;
	_numberScale = scale;
	_numberMaxValue = numValueIndex;
}

void Number::SetPosition(Vector2 numberPosition)
{
	_numberPos.x = numberPosition.x;
	_numberPos.y = numberPosition.y;
}

void Number::SetMove(bool left) {
	_slideInUI.SetStatu(_numberPos.x, &_numberPos.x, left);
}

void Number::ReLoad() {
	_slideInUI.Start();
}

void Number::Update() {
	_slideInUI.Update();
}

CRectangle Number::CalcuRect()
{
	return CRectangle(_numberTexture->GetWidth() / _numberMaxValue * _currentValue, 0,
		_numberTexture->GetWidth() / _numberMaxValue * (_currentValue + 1), _numberTexture->GetHeight());
}

void Number::Render()
{
	_numberTexture->RenderScale(_numberPos.x, _numberPos.y, _numberScale, CalcuRect());
}