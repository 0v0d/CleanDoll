#include "GameOverDollAnimation.h"


void GameOverDollAnimation::Initialize()
{
	LoadTexture();
	_pos = Vector2(1000, 350);
	SpriteAnimationCreate anim[] =
	{
		{
			"No1",
			0,0,
			320,320,
			TRUE,{
					{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},
					{3,11,0},{3,12,0},{3,13,0},{3,14,0},{3,15,0},{3,16,0},{3,17,0},{3,18,0},{3,19,0},{3,20,0},
					{3,21,0},{3,22,0},{3,23,0},{3,24,0},{3,25,0},{3,26,0},{3,27,0},{3,28,0},{3,29,0}
				 }
		},
	};
	_animation.Create(anim, 1);
}
void GameOverDollAnimation ::LoadTexture () {
	_dollTexture.Load("gameoverdoll.png");
}

void GameOverDollAnimation::ReLoad() {

}

void GameOverDollAnimation::Update()
{
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_dollRect = _animation.GetSrcRect();
}

void GameOverDollAnimation::Render()
{
	
	_dollTexture.RenderScale(_pos.x, _pos.y, _scale, _dollRect);
}

void GameOverDollAnimation::Release()
{
	_dollTexture.Release();
}