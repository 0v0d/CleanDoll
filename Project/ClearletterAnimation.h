#pragma once
#include	"Mof.h"
class ClearletterAnimation
{
private:
	CTexture	LetterTexture;
	CSpriteMotionController		LetterMotion;
	float scale;
public:
	void Initialize();
	void LoadTexture();
	void Update();
	void Rnder();
	void Release();
};

