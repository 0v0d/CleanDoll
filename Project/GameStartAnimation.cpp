#include "GameStartAnimation.h"

void GameStartAnimation::Initialize() {
	LoadTexture();
	CreateAnimation();

	_end = true;
}

void GameStartAnimation::LoadTexture() {
	_animationTexture.Load("gameStartAnimation.png");
}

void GameStartAnimation::CreateAnimation() {
	const float animationValueX = 10;
	const int animationValueY = 5;
	Vector2 rectSize = Vector2(_animationTexture.GetWidth() / animationValueX, _animationTexture.GetHeight() / animationValueY);
	int number = 0;
	CalcuPosition(rectSize);
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

void GameStartAnimation::StartCleanAnimation() {
	_currentMotion = 0;
	_motionController.ChangeMotion(0); 
	_end = false;
}

void GameStartAnimation::Update() {
	if (_end) return;

	_motionController.AddTimer(CUtilities::GetFrameSecond());
	_renderRect = _motionController.GetSrcRect();
	if (_motionController.IsEndMotion()) SetNextAnimation();
}

void GameStartAnimation::SetNextAnimation() {

	_currentMotion++;
	_motionController.ChangeMotion(_currentMotion);

	if (_motionController.IsEndMotion() && _motionController.GetMotionNo() == _motionValue - 1)_end = true;
}

void GameStartAnimation::Render() {
	if (_end) return;
	_animationTexture.Render(_pos.x, _pos.y, _renderRect);
}

void GameStartAnimation::Release() {
	_animationTexture.Release();
}