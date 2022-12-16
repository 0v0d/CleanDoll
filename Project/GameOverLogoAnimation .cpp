#include "GameOverLogoAnimation.h"

void GameOverLogoAnimation::Initialize()
{
	_missTakeLogTexture.Load("gameover.png");
	_pos = Vector2(-100, 0);
	float _speed = 5;
	SpriteAnimationCreate anim[] =
	{
		{
			"No1",
			0,0,
			//新たな画像が来た時、21要素にする。またxの座標も変える
			490,270,
			FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},
				{3,11,0},{3,12,0},{3,13,0},{3,14,0},{3,15,0},{3,16,0},{3,17,0},{3,18,0},{3,19,0},{3,20,0},
				{3,21,0},{3,22,0},{3,23,0},{3,24,0},{3,25,0},{3,26,0},{3,27,0},{3,28,0},{3,29,0}}
		},
	};
	_animation.Create(anim, 1);
}

void GameOverLogoAnimation::ReLoad() {
	_animation.SetTime(0);
	_missTakeLogRect = CRectangle(0, 0, 0, 0);
}

void GameOverLogoAnimation::Update()
{
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_missTakeLogRect = _animation.GetSrcRect();
}

void GameOverLogoAnimation::Render()
{
	_missTakeLogTexture.RenderScale(_pos.x, _pos.y, _scale, _missTakeLogRect);
}

void GameOverLogoAnimation::Release()
{
	_missTakeLogTexture.Release();
}