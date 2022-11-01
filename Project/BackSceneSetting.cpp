#include "BackSceneSetting.h"

void BackSceneSetting::Initialize() {
	_closeButton = CRectangle(g_pGraphics->GetTargetWidth() / 2 - 50, 400, g_pGraphics->GetTargetWidth() / 2 + 50, 450);
}

void BackSceneSetting::Update() {

}

void BackSceneSetting::Push(Vector2 mousePos) {
	PushButton(mousePos);
}

void BackSceneSetting::Pull(Vector2 mousePos) {

}

void BackSceneSetting::PushButton(Vector2 mousePos) {
	if (_closeButton.CollisionPoint(mousePos)) {
		*_openBackSceneSetting = false;
	}
}

void BackSceneSetting::Render() {
	CGraphicsUtilities::RenderFillRect(_closeButton, MOF_COLOR_HGREEN);
}

void BackSceneSetting::Release() {

}