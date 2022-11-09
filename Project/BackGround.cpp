#include "BackGround.h"

void BackGround::SetTextureName(CTexture* textureName)
{
	_backTexture = textureName;
	_backRect = CRectangle(0, 0,
		g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight());
}
void BackGround::Render()
{
	_backTexture->Render(0, 0, _backRect);
}