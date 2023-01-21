#include "GameClearBackGround.h"

void GameClearBackGround::Initialize()
{
	LoadTexture();
	CalcuPosition();
	SpriteAnimationCreate anim[] =
	{
		{
			"No1",
			0,0,
			480,270,
			FALSE,
			{
				{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},
				{3,11,0},{3,12,0},{3,13,0},{3,14,0},{3,15,0},{3,16,0},{3,17,0},{3,18,0},{3,19,0},{3,20,0},
				{3,21,0},{3,22,0},{3,23,0},{3,24,0},{3,25,0},{3,26,0},{3,27,0},{3,28,0},{3,29,0}
			}
		},
	};
	_animation.Create(anim, 1);
}

void GameClearBackGround::LoadTexture() {
	_gameClearBackGroundTexture.Load("clearback.png");

}

void GameClearBackGround::ReLoad() {
	_animation.SetTime(0);
}

void GameClearBackGround::Update()
{
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_gameClearBackGroundRect = _animation.GetSrcRect();
}

void GameClearBackGround::CalcuPosition()
{
	_pos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _gameClearBackGroundTexture.GetWidth() / 30 / 2 * _scale,
		g_pGraphics->GetTargetHeight() / 2 - _gameClearBackGroundTexture.GetHeight() / 2 * _scale);
}

void GameClearBackGround::Render()
{
	_gameClearBackGroundTexture.RenderScale(_pos.x, _pos.y, _scale, _gameClearBackGroundRect);
}

void GameClearBackGround::Release()
{
	_gameClearBackGroundTexture.Release();
}


