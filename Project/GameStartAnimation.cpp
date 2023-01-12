#include "GameStartAnimation.h"

void GameStartAnimation::Initialize() {
	CreateAnimation();
}

void GameStartAnimation::LoadTexture() {
	_animationTexture.Load("gameStartAnimation.png");
}

void GameStartAnimation::CreateAnimation() {
	const float animationValueX = 10;
	const int animationValueY = 5;
	Vector2 rectSize = Vector2(_animationTexture.GetWidth() / animationValueX, _animationTexture.GetHeight() / animationValueY);
	int number = 0;
	SpriteAnimationCreate gameStartAnimation[] = {
{
	"Game_Start",
	0,rectSize.y* number++,
	rectSize.x,rectSize.y,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0}}
},
{
	"Game_Start",
	0,rectSize.y* number++,
	rectSize.x,rectSize.y,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0}}
},
{
	"Game_Start",
	0,rectSize.y* number++,
	rectSize.x,rectSize.y,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0}}
},
{
	"Game_Start",
	0,rectSize.y* number++,
	rectSize.x,rectSize.y,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0}}
},
		{
	"Game_Start",
	0,rectSize.y* number++,
	rectSize.x,rectSize.y,
	false,{{_wait,0,0},{_wait,1,0},{_wait,2,0},{_wait,3,0},{_wait,4,0},{_wait,5,0},{_wait,6,0},{_wait,7,0},
	{_wait,8,0},{_wait,9,0}}
},
	};
	_motionController.Create(gameStartAnimation, _motionValue);
}

void GameStartAnimation::CalcuPosition(Vector2 rectSize) {
	_pos.x = g_pGraphics->GetTargetWidth() / 2 - rectSize.x / 2 ;
	_pos.y = g_pGraphics->GetTargetHeight() / 2 - rectSize.y / 2;
}

void GameStartAnimation::ReLoad() {
}

void GameStartAnimation::SetNextAnimation() {
}

void GameStartAnimation::Update() {
}

void GameStartAnimation::Render() {
}

void GameStartAnimation::Release() {
}


