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
			FALSE,{{_speed,0,0},{10,1,0},{_speed,2,0},{_speed,3,0},{_speed,4,0},{_speed,5,0},{_speed,6,0},{_speed,7,0},{_speed,8,0},{_speed,9,0},{_speed,10,0},
					{_speed,11,0},{_speed,12,0},{_speed,13,0},{_speed,14,0},{_speed,15,0},{_speed,16,0},{_speed,17,0},{_speed,18,0},{_speed,19,0},{_speed,20,0},{_speed,21,0},{_speed,22,0}}
		},
	};
	_animation.Create(anim, 1);
}

void GameOverLogoAnimation::ReLoad() {

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