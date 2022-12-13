#include "FadeOut.h"
#include "Mof.h"

void FadeOut::Initialize() {
	Alpha = 0;
	fadeOut = false;
	Change = false;
}

void FadeOut::Update() {
	if (fadeOut) {
		if (Alpha <255) {
			Alpha += 5;
		}
		else {
			Change = true;
		}
	}
	
}

void FadeOut::Render() {
	if (fadeOut)
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(Alpha, 0, 0, 0));
}