#include "TitleLogoAnimation.h"

void TitleLogoAnimation::Initialize(){
	LoadTexture();
	CreateAnimation();

	_currentAniamtion = &_logoAnimation;
	_currentAnimationTexture = &_logoTexture;
	_loopAnimation = false;
}

void TitleLogoAnimation::LoadTexture(){
	_logoTexture.Load("taitlelog.png");
	_loopLogoTexture.Load("titleloop.png");
}

void TitleLogoAnimation::CreateAnimation() {
	const int animationValueX = 15;
	const int animationValueY = 10;
	Vector2 rectSize = Vector2(_logoTexture.GetWidth() / animationValueX, _logoTexture.GetHeight() / animationValueY);
	CalcuPosition(rectSize);
	int number = 0;
	
	SpriteAnimationCreate logoAnimation[] =
	{
	  {
		  "1-1",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-2",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-3",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-4",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-5",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-6",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-7",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-8",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-9",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-10",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  },
	  {
		  "1-11",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0},{2,7,0},{2,8,0},{2,9,0},{2,10,0},{2,11,0},{2,12,0},{2,13,0},{2,14,0}}
	  }
	};
	_logoAnimation.Create(logoAnimation, _logoAnimationValue);

	SpriteAnimationCreate loopLogoAnimation[] =
	{
	  {
		"2-1",
			0, 0,
			750, 625,
			FALSE, { {3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0} }
	},
	  {
		  "2-2",
		  0,625,
		  750,625,
		  FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	  },
	  {
		  "2-3",
		  0,1250,
		  750,625,
		  FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	  },
	  {
		  "2-4",
		  0,1875,
		  750,625,
		  FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	  },
	  {
		  "2-5",
		  0,2500,
		  750,625,
		  FALSE,{{3,0,0},{3,1,0},{3,2,0},{3,3,0},{3,4,0},{3,5,0},{3,6,0},{3,7,0},{3,8,0},{3,9,0}}
	  }
	};

	_loopLogoAnimation.Create(loopLogoAnimation, _loopLogoAnimationValue);
}

void TitleLogoAnimation::CalcuPosition(Vector2 rectSize) {
	const int supX = -50;
	const int supY = -100;

	_pos.x = g_pGraphics->GetTargetWidth() / 2 - rectSize.x / 2 * _scale + supX;
	_pos.y = g_pGraphics->GetTargetHeight() / 2 - rectSize.y / 2 * _scale + supY;
}


void TitleLogoAnimation::ReLoad(){
	_currentAniamtion = &_logoAnimation;
	_currentAnimationTexture = &_logoTexture;

	_logoCount = 0;
	_loopAnimation = false;
}

void TitleLogoAnimation::Update() {
	_currentAniamtion->AddTimer(CUtilities::GetFrameSecond());
	SetNextAnimation();
	_renderRect = _currentAniamtion->GetSrcRect();
}

void TitleLogoAnimation::SetNextAnimation() {


	if (_loopAnimation) {
		if (_logoCount > _loopLogoAnimationValue) {
			_logoCount = 0;
		}
	}
	else if (_logoCount > _logoAnimationValue) {
		_currentAniamtion = &_loopLogoAnimation;
		_currentAnimationTexture = &_loopLogoTexture;
		_loopAnimation = true;
		_logoCount = 0;
	}

	_currentAniamtion->ChangeMotion(_logoCount);
	_logoCount++;
}

void TitleLogoAnimation::Render() {
	_currentAnimationTexture->RenderScale(_pos.x, _pos.y, _scale, _renderRect);
}

void TitleLogoAnimation::Release(){
	_logoTexture.Release();
	_loopLogoTexture.Release();
}