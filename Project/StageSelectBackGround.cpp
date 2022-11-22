#include "StageSelectBackGround.h"

void StageSelectBackGround::Initialize() {
	_ScrollY = 0;
	_ScrollSpeed = 1;
}
void StageSelectBackGround::Update(){
	_ScrollY -= _ScrollSpeed;
	_ScrollX += _ScrollSpeed;
}

void StageSelectBackGround::SetTextureStatus(CTexture* backGroundTexture)
{
	_backTexture = backGroundTexture;
	_backRect = CRectangle(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
}

void StageSelectBackGround::Render()
{
	int h = _backTexture->GetHeight();
	int sch = g_pGraphics->GetTargetHeight();
	int w = _backTexture->GetWidth();
	int scw = g_pGraphics->GetTargetWidth();
	
	for (float y = ((int)_ScrollY % h) - h; y < sch; y += h) {
		for (float x = ((int)_ScrollX % w) - h; x < scw; x += h) {
			_backTexture->Render(x, y);

		}
	}
}