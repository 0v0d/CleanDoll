#include "BackGround.h"

void BackGround::SetTextureStatus(CTexture* backGroundTexture, SCREEN_TYPE typeName)
{
	_backTexture = backGroundTexture;
	_typeName = typeName;
	_backRect = CRectangle(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
}


void BackGround::Render()
{
	if(_typeName==REPEATSCREEN)_backTexture->Render(0, 0, _backRect);
	else if (_typeName== FULLSCREEN)_backTexture->Render(_backRect);
}