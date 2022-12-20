#include "FadeIn.h"

FadeIn::FadeIn() :
	_subAlphaValue(1),
	_end(true)
{}

void FadeIn::SetTime(int fadeInFrame) {
	_subAlphaValue = _maxAlpha / fadeInFrame;
}

void FadeIn::Start() {
	_alpha = _maxAlpha;
	_end = false;
}

void FadeIn::Update() {
	if (_end) return;

	_alpha -= _subAlphaValue;
	if (_alpha <=0) {
		_alpha = 0;
		_end = true;
	}
}

void FadeIn::Render() {
	if (_end) return;
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(_alpha, 0, 0, 0));
}