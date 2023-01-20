#include "EndTutorialBackGround.h"

void EndTutorialBackGround::Initialize()
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

void EndTutorialBackGround::LoadTexture() {
	_endTutorialGameClearTexture.Load("clearback.png");

}

void EndTutorialBackGround::ReLoad() {
	_animation.SetTime(0);
}

void EndTutorialBackGround::Update()
{
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_endTutorialGameClearRect = _animation.GetSrcRect();
}

void EndTutorialBackGround::CalcuPosition()
{
	_pos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _endTutorialGameClearTexture.GetWidth() / 30 / 2 * _scale,
		g_pGraphics->GetTargetHeight() / 2 - _endTutorialGameClearTexture.GetHeight() / 2 * _scale);
}

void EndTutorialBackGround::Render()
{
	_endTutorialGameClearTexture.RenderScale(_pos.x, _pos.y, _scale, _endTutorialGameClearRect);
}

void EndTutorialBackGround::Release()
{
	_endTutorialGameClearTexture.Release();
}


