#include "EndGameButtonAnimation.h"

void EndGameButtonAnimation::Initialize()
{
	_targetScale = 1.0f;
	_animationSpeed = 0.1f;
	_endAnimation = false;

}

void EndGameButtonAnimation::ReLoad()
{
	_scale = 0.0f;
	if (_endAnimation)CalcuButtonRect();
	_endAnimation = false;
}

void EndGameButtonAnimation::SetTexture(CTexture* buttonAnimTexutre) {
	_buttonAnimTexture = buttonAnimTexutre;
}

void EndGameButtonAnimation::CalcuTargetScale(float targetSizeY) {
	_targetScale = targetSizeY / _buttonAnimTexture->GetHeight();
}

void EndGameButtonAnimation::CalcuCenterPos(Vector2 buttonAnimCenterPos) {
	_buttonAnimPos.x = buttonAnimCenterPos.x - _buttonAnimTexture->GetWidth() * _targetScale / 2;
	_buttonAnimPos.y = buttonAnimCenterPos.y - _buttonAnimTexture->GetHeight() * _targetScale / 2;
}

void EndGameButtonAnimation::CalcuAnimationSpeed(int animationTime) {
	_animationSpeed = _targetScale / animationTime;
}

void EndGameButtonAnimation::Update()
{
	if (_endAnimation) return;

	UpdateAnimation();
	CalcuButtonRect();
}

void EndGameButtonAnimation::UpdateAnimation() {
	_scale += _animationSpeed;

	if (_scale >= _targetScale)
	{
		_endAnimation = true;
		_scale = _targetScale;
	}
}

void EndGameButtonAnimation::CalcuButtonRect() {
	float textureWideth = _buttonAnimTexture->GetWidth();

	_buttonAnimRect = CRectangle
	(_buttonAnimPos.x + textureWideth * _targetScale / 2 - textureWideth * _scale / 2,
		_buttonAnimPos.y,
		_buttonAnimPos.x + textureWideth * _targetScale / 2 + textureWideth * _scale / 2,
		_buttonAnimPos.y + _buttonAnimTexture->GetHeight() * _targetScale);
}

void EndGameButtonAnimation::Render()
{
	_buttonAnimTexture->Render(_buttonAnimRect);
}