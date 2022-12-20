#include "EndTutorialBackGround.h"

void EndTutorialBackGround::Initialize()
{
	LoadTexture();
}

void EndTutorialBackGround::LoadTexture()
{
	_backGroundTexture.Load("BackStageClear.png");
}

void EndTutorialBackGround::ReLoad()
{
	_scale = 0;
	_fixedScale = false;
}

void EndTutorialBackGround::Update()
{
	CalcuScale();
	CalcuPosition();
}

void EndTutorialBackGround::CalcuScale()
{
	_scale += 0.1f;
	_fixedScale = _scale >= 1.0f;
}

void EndTutorialBackGround::CalcuPosition()
{
	_pos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _backGroundTexture.GetWidth() / 2 * _scale,
		g_pGraphics->GetTargetHeight() / 2 - _backGroundTexture.GetHeight() / 2 * _scale);
}

void EndTutorialBackGround::Render()
{
	_backGroundTexture.RenderScale(_pos.x, _pos.y, _scale);
}

void EndTutorialBackGround::Release()
{
	_backGroundTexture.Release();
}