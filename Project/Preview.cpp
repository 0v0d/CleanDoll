#include "Preview.h"

void Preview::Initialize() {
	LoadTexture();
}

void Preview::LoadTexture() {
	_baseTexture.Load("stagepreview_base.png");
	_frameTexture.Load("stagepreview_flame.png");
}


void Preview::CalcuBaseScale(float BarBaseTextureHeight) {
	_baseScale = BarBaseTextureHeight / _baseTexture.GetHeight();
	_frameScale = (float)_frameTexture.GetHeight() / (float)_baseTexture.GetHeight();
}

void Preview::CalcuBasePos() {
	_basePos.x = g_pGraphics->GetTargetWidth() - _baseTexture.GetWidth() * _baseScale - 80;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2 - _baseTexture.GetHeight() * _baseScale / 2;
}

void Preview::SetPreviewTexture(CTexture* previewTexture)
{
	_previewTexture = previewTexture;
	CalcuPreviewScale();
	SetPosistion();
}

void Preview::CalcuPreviewScale() {
	_previewScale = _baseTexture.GetHeight() * _baseScale / _previewTexture->GetHeight()*0.7;
}

void Preview::SetPosistion()
{
	_previewPosition.x = _basePos.x + _baseTexture.GetWidth() * _baseScale / 2 - _previewTexture->GetWidth() * _previewScale / 2;
	_previewPosition.y = _basePos.y + _baseTexture.GetHeight() * _baseScale / 2 - _previewTexture->GetHeight() * _previewScale / 2;
}

void Preview::Render()
{
	_baseTexture.RenderScale(_basePos.x, _basePos.y, _baseScale);
	_previewTexture->RenderScale(_previewPosition.x, _previewPosition.y, _previewScale);
	_frameTexture.RenderScale(_basePos.x, _basePos.y, _frameScale);
}

void Preview::Release() {
	_baseTexture.Release();
	_frameTexture.Release();
}