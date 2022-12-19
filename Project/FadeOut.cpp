#include "FadeOut.h"

FadeOut::FadeOut() :_addAlphaValue(1) {}

void FadeOut::SetTime(int FadeOutFrame) {
	_addAlphaValue = _maxAlpha / FadeOutFrame;
}

void FadeOut::Start() {
	_alpha = 0;
	_end = false;
}

void FadeOut::Update() {
	if (_end) return;

	_alpha += _addAlphaValue;
	if (_alpha >=_maxAlpha) {
		_alpha = _maxAlpha;
		_end = true;
	}
}

void FadeOut::Render() {
	if (_end) return;
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(_alpha, 0, 0, 0));
}