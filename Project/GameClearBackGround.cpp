#include "GameClearBackGround.h"

void GameClearBackGround::Initialize()
{
	_backGroundTexture.Load("BackStageClear.png");
	_scale = 0;
	_isFixedScale = false;
}
void GameClearBackGround::Update()
{
	_scale += 0.1f;
}
void GameClearBackGround::ScaleRender()
{
	_backGroundTexture.RenderScale(g_pGraphics->GetTargetWidth() / 2 - _backGroundTexture.GetWidth() / 2 * _scale,
		g_pGraphics->GetTargetHeight() / 2 - _backGroundTexture.GetHeight() / 2 * _scale, _scale);
	if (_scale >= 1.0f)
	{
		_isFixedScale = true;
	}
}
void GameClearBackGround::Release()
{
	_backGroundTexture.Release();
}


