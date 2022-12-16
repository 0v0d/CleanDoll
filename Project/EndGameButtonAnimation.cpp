#include "EndGameButtonAnimation.h"

void EndGameButtonAnimation::Initialize()
{
}
void EndGameButtonAnimation::ReLoad()
{
	_scaleValeu = 0.0f;
	_endAnimation = false;
}

void EndGameButtonAnimation::SetStatu(Vector2 buttonAnimPos, CTexture* buttonAnimTexutre)
{
	_buttonAnimTexture = buttonAnimTexutre;
	_buttonAnimPos = buttonAnimPos;
}

void EndGameButtonAnimation::Update()
{
	if (_endAnimation) return;

	UpdateAnimation();
	if (_scaleValeu >= 1.0f)
	{
		_endAnimation = true;
	}
}

void EndGameButtonAnimation::UpdateAnimation() {
	float _textureWideth = _buttonAnimTexture->GetWidth() / 2;
	_scaleValeu += 0.1f;
	_buttonAnimRect = CRectangle
	(_buttonAnimPos.x + _textureWideth - _textureWideth * _scaleValeu,
		_buttonAnimPos.y,
		_buttonAnimPos.x + _textureWideth + _textureWideth * _scaleValeu,
		_buttonAnimPos.y + _buttonAnimTexture->GetHeight());
}

void EndGameButtonAnimation::Render()
{
	_buttonAnimTexture->Render(_buttonAnimRect);
}