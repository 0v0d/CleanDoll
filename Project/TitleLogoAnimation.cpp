#include "TitleLogoAnimation.h"

void TitleLogoAnimation::Initialize(){
	LoadTexture();
	CreateAnimation();

	_currentAniamtion = &_logoAnimation[0];
	_currentAnimationTexture = &_logoTextureArray[0];
	_loopAnimation = false;
	_renderRect = _currentAniamtion->GetSrcRect();
}

void TitleLogoAnimation::LoadTexture(){

	_contactFile.OpenFile("TitleAnimation.txt");
	_animationValue = _contactFile.GetValue(true);
	_logoTextureArray = new CTexture[_animationValue];

	for (int i = 0;i < _animationValue;i++){
		_logoTextureArray[i].Load(_trim.TrimString(_contactFile.GetString(false)).c_str());
	}

	_contactFile.CloseFile();
}

void TitleLogoAnimation::CreateAnimation() {
	_animationY = 3;
	_logoAnimation = new CSpriteMotionController[_animationValue];
	for (int i = 0;i < _animationValue;i++) {
		CreateLogoAnimation(i);
	}
}

void TitleLogoAnimation::CreateLogoAnimation(int logoNumber) {
	const int animationValueX = 5;
	Vector2 rectSize = Vector2(_logoTextureArray[logoNumber].GetWidth() / animationValueX, _logoTextureArray[logoNumber].GetHeight() / _animationY);
	CalcuPosition(rectSize);
	int number = 0;

	const int frame = 3;

	SpriteAnimationCreate logoAnimation[] =
	{
	  {
		  "1-1",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0}}
	  },
	  {
		  "1-2",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0}}
	  },
	  {
		  "1-3",
		  0,rectSize.y * number++,
		  rectSize.x,rectSize.y,
		  FALSE,{{frame,0,0},{frame,1,0},{frame,2,0},{frame,3,0},{frame,4,0}}
	  }
	};
	_logoAnimation[logoNumber].Create(logoAnimation, _animationY);
}

void TitleLogoAnimation::CalcuPosition(Vector2 rectSize) {
	const int supX = -50;
	const int supY = -100;

	_pos.x = g_pGraphics->GetTargetWidth() / 2 - rectSize.x / 2 * _scale + supX;
	_pos.y = g_pGraphics->GetTargetHeight() / 2 - rectSize.y / 2 * _scale + supY;
}


void TitleLogoAnimation::ReLoad(){
	_currentAniamtion = &_logoAnimation[0];
	_currentAnimationTexture = &_logoTextureArray[0];

	_logoCount = 0;
	_loopAnimation = false;
}

void TitleLogoAnimation::Update() {
	_currentAniamtion->AddTimer(CUtilities::GetFrameSecond());
	_renderRect = _currentAniamtion->GetSrcRect();
	SetNextAnimation();
}

void TitleLogoAnimation::SetNextAnimation() {
	if (!_currentAniamtion->IsEndMotion()) return;

	_animationCount++;

	if (_animationCount < _animationY) {
		_logoAnimation[_logoCount].ChangeMotion(_animationCount);
		return;
	}

	_logoCount++;
	_animationCount = 0;

	_logoAnimation[_logoCount].ChangeMotion(_animationCount);
	_currentAniamtion = &_logoAnimation[_logoCount];
	_currentAnimationTexture = &_logoTextureArray[_logoCount];
	_renderRect = _currentAniamtion->GetSrcRect();
}

void TitleLogoAnimation::Render() {
	_currentAnimationTexture->RenderScale(_pos.x, _pos.y, _scale, _renderRect);
}

void TitleLogoAnimation::Release(){
	for (int i = 0;i < _animationValue;i++) {
		_logoTextureArray[i].Release();
	}
	delete[] _logoTextureArray;
	delete[] _logoAnimation;
}