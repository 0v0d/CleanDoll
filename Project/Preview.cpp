#include "Preview.h"

void Preview::SetPreviewTexture(CTexture* previewTexture)
{ 
	_previewTexture = previewTexture; 
	SetPosistion();
}

void Preview::SetPosistion()
{
	_previewPosition.x = g_pGraphics->GetTargetWidth() - _previewTexture->GetWidth() - _space;
	_previewPosition.y = g_pGraphics->GetTargetHeight() / 2 - _previewTexture->GetHeight() / 2;
}

void Preview::Render()
{
	_previewTexture->Render(_previewPosition.x, _previewPosition.y);
}