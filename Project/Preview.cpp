#include "Preview.h"

void Preview::Initialize() {
	LoadTexture();
}

void Preview::LoadTexture() {
	_baseTexture.Load("プレビュー枠.png");
}


void Preview::CalcuBaseScale(float BarBaseTextureHeight) {
	_baseScale = BarBaseTextureHeight / _baseTexture.GetHeight();
}

void Preview::CalcuBasePos(float space) {
	_basePos.x = g_pGraphics->GetTargetWidth() - _baseTexture.GetWidth() * _baseScale - space;
	_basePos.y = g_pGraphics->GetTargetHeight() / 2 - _baseTexture.GetHeight() * _baseScale / 2;
}

void Preview::SetPreviewTexture(CTexture* previewTexture)
{
	_previewTexture = previewTexture;
	CalcuPreviewScale();
	SetPosistion();
}

void Preview::SetPosistion()
{
	_previewPosition.x = _basePos.x + _baseTexture.GetWidth() * _baseScale / 2 - _previewTexture->GetWidth() * _previewScale / 2;
	_previewPosition.y = _basePos.y + _baseTexture.GetHeight() * _baseScale / 2 - _previewTexture->GetHeight() * _previewScale / 2;
}

void Preview::CalcuPreviewScale() {
	_previewScale = _baseTexture.GetHeight() * _baseScale / _previewTexture->GetHeight();
}

void Preview::Render()
{
	_baseTexture.RenderScale(_basePos.x, _basePos.y, _baseScale);
	_previewTexture->RenderScale(_previewPosition.x, _previewPosition.y, _previewScale);
}

void Preview::Release() {
	_baseTexture.Release();
}