#include "GameOverBackGround.h"

void GameOverBackGround::Initialize()
{
	_gameOverBackGroundTexture.Load("GameOverBackGround.png");
	CalcuPosition();
	SpriteAnimationCreate anim[] =
	{
		{
			"No1",
			0,0,
			490,270,
			FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},{3,11,0},{3,12,0},
					{3,13,0},{3,14,0},{3,15,0},{3,16,0},{3,17,0},{3,18,0},{3,19,0}}
		},
	};
	_animation.Create(anim, 1);
}

void GameOverBackGround::ReLoad() {
	_animation.SetTime(0);
}

void GameOverBackGround::Update()
{
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_gameOverBackGroundRect = _animation.GetSrcRect();
}

void GameOverBackGround::CalcuPosition() 
{
	_pos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _gameOverBackGroundTexture.GetWidth()/20 / 2 * _scale,
		g_pGraphics->GetTargetHeight() / 2 - _gameOverBackGroundTexture.GetHeight() / 2 * _scale);
}

void GameOverBackGround::Render()
{
	_gameOverBackGroundTexture.RenderScale(_pos.x,_pos.y,_scale,_gameOverBackGroundRect);
}

void GameOverBackGround::Release()
{
	_gameOverBackGroundTexture.Release();
}


