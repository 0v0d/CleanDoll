#include "GameClearLogoAnimation.h"

void GameClearLogoAnimation::Initialize()
{
	_stageClearTexture.Load("�X�e�[�W�N���A.png");
	_pos = Vector2(0, 0);
	SpriteAnimationCreate anim[] =
	{
		{
			"No1",
			0,0,
			480,270,
			FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0},{3,10,0},{3,11,0},{3,12,0},
					{3,13,0},{3,14,0},{3,15,0},{3,16,0},{3,17,0},{3,18,0},{3,19,0},{3,20,0},{3,21,0},{3,22,0}}
		},
	};
	_animation.Create(anim, 1);
}

void GameClearLogoAnimation::ReLoad() {

}

void GameClearLogoAnimation::Update()
{
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_clearLogRect = _animation.GetSrcRect();
}

void GameClearLogoAnimation::Render()
{
	_stageClearTexture.RenderScale(_pos.x, _pos.y, _scale, _clearLogRect);
}

void GameClearLogoAnimation::Release()
{
	_stageClearTexture.Release();
}