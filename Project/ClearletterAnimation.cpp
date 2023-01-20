#include "ClearletterAnimation.h"

void ClearletterAnimation::Initialize() {
	LoadTexture();
	SpriteAnimationCreate anim = {
		"‚¨‘|œŠ®—¹",
		0,0,
		470,57,
		TRUE,{{10,0,0},{10,1,0}}
	};
	LetterMotion.Create(anim);

	scale = 1.0f;
}

void ClearletterAnimation::LoadTexture() {
	LetterTexture.Load("‚¨‘|œ‚ðŠ®—¹‚·‚é ˜AŒ‹.png");
}

void ClearletterAnimation::Update() {
	LetterMotion.AddTimer(CUtilities::GetFrameSecond());
}

void ClearletterAnimation::Rnder() {
	LetterTexture.RenderScale(g_pGraphics->GetTargetWidth()/2- LetterTexture.GetWidth()/4, LetterTexture.GetHeight()/3,scale, LetterMotion.GetSrcRect());
}

void ClearletterAnimation::Release() {
	LetterTexture.Release();
}