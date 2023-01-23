#include "GameClearAnimation.h"

void GameClearAnimation::Initialize() {
	LoadTexture();
	CreateAnimation();
	_pos = Vector2(0, 0);
}

void GameClearAnimation::LoadTexture() {
	_gameOverTexture.Load("Gameclear.dds");
}

void GameClearAnimation::CreateAnimation() {
	const int animationValueX = 6;
	const int animationValueY = 5;
	Vector2 rectSize = Vector2(_gameOverTexture.GetWidth() / animationValueX, _gameOverTexture.GetHeight() / animationValueY);
	int number = 0;
	const float frame = 3;
	SpriteAnimationCreate animation[] =
	{
		{
		  "GameClear1",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },
		{
		  "GameClear2",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },
		{
		  "GameClear3",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },
		{
		  "GameOve4",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },
		{
		  "GameClear5",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },

	};
	_animation.Create(animation, _animationValue);
}

void GameClearAnimation::ReLoad() {
	_animationCount = 0;
	_animation.ChangeMotion(_animationCount);
}

void GameClearAnimation::Update() {
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_renderRect = _animation.GetSrcRect();
	SetNextAnimation();
}

void GameClearAnimation::SetNextAnimation() {
	if (!_animation.IsEndMotion()) return;
	_animationCount++;
	_animation.ChangeMotion(_animationCount);
}

void GameClearAnimation::Render() {
	_gameOverTexture.Render(_pos.x, _pos.y, _renderRect);
}

void GameClearAnimation::Release() {
	_gameOverTexture.Release();
}