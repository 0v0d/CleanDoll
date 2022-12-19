#include "FadeIn.h"
#include "Mof.h"

void FadeIn::Initialize() {
	Alpha = 255;
	fadeIn = false;
}

void FadeIn::Update() {
	if (fadeIn) {
		if (Alpha >= 0) {
			Alpha -= 5;
			if (Alpha <= 0) {
				fadeIn = false;
			}
		}
	}
	
}

void FadeIn::Render() {
	if (fadeIn)
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(Alpha, 0, 0, 0));
}