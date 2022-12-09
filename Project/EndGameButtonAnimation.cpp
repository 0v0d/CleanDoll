#include "EndGameButtonAnimation.h"

void EndGameButtonAnimation::Initialize()
{
}
void EndGameButtonAnimation::ReLoad()
{
	_scaleValeu = 0.0f;
	_endAnimation = false;
}

void EndGameButtonAnimation::Update()
{
	if (_endAnimation) return;

	float _textureWideth = _buttonAnimTexture->GetWidth() / 2;
	_scaleValeu += 0.1f;
	_buttonAnimRect = CRectangle
	(_buttonAnimPos.x + _textureWideth - _textureWideth * _scaleValeu,
		_buttonAnimPos.y,
		_buttonAnimPos.x + _textureWideth + _textureWideth * _scaleValeu,
		_buttonAnimPos.y + _buttonAnimTexture->GetHeight());
	if (_scaleValeu >= 1.0f)
	{
		_endAnimation = true;
	}
}

void EndGameButtonAnimation::Render()
{

	_buttonAnimTexture->Render(_buttonAnimRect);

}

void EndGameButtonAnimation::Release()
{
	_buttonAnimTexture->Release();
}