#include "GameClearBackGround.h"

void GameClearBackGround::Initialize()
{
	LoadTexture();
}

void GameClearBackGround::LoadTexture() {
	_backGroundTexture.Load("BackStageClear.png");
}

void GameClearBackGround::ReLoad() {
	_scale = 0.0f;
	_fixedScale = false;
}

void GameClearBackGround::Update()
{
	CalcuScale();
	CalcuPosition();
}

void GameClearBackGround::CalcuScale() {
	_scale += 0.1f;
	_fixedScale = _scale >= 1.0f;
}

void GameClearBackGround::CalcuPosition() {
	_pos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _backGroundTexture.GetWidth() / 2 * _scale,
		g_pGraphics->GetTargetHeight() / 2 - _backGroundTexture.GetHeight() / 2 * _scale);
}

void GameClearBackGround::Render()
{
	_backGroundTexture.RenderScale(_pos.x, _pos.y, _scale);
}

void GameClearBackGround::Release()
{
	_backGroundTexture.Release();
}


