#include "GameOverAnimation.h"

void GameOverAnimation::Initialize() {
	LoadTexture();
	CreateAnimation();

}

void GameOverAnimation::LoadTexture() {
	_gameOverTexture.Load("Gameover.png");
}

void GameOverAnimation::CreateAnimation() {
	const int animationValueX = 6;
	const int animationValueY = 5;
	Vector2 rectSize = Vector2(_gameOverTexture.GetWidth() / animationValueX, _gameOverTexture.GetHeight() / animationValueY);
	CalcuPosition(rectSize);
	int number = 0;
	const float frame = 2;
	SpriteAnimationCreate animation[] =
	{
		{
		  "GameOver1",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },
		{
		  "GameOver2",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },
		{
		  "GameOver3",
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
		  "GameOver5",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0},{frame,5,0},}
	  },

	};
	_animation.Create(animation,_animationValue);
}

void GameOverAnimation::ReLoad() {
	_animationCount = 0;
}

void GameOverAnimation::Update() {
	_animation.AddTimer(CUtilities::GetFrameSecond());
	_renderRect = _animation.GetSrcRect();

}

void GameOverAnimation::SetNextAnimation() {
	if (!_animation.IsEndMotion()) return;
	_animation.ChangeMotion(_animationCount);
	_animationCount++;
}

void GameOverAnimation::Render() {
	_gameOverTexture.Render(0, 0, _renderRect);
}

void GameOverAnimation::Release() {
	_gameOverTexture.Release();
}



