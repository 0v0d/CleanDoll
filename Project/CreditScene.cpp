#include "CreditScene.h"

void CreditScene::Initialize() {
}

void CreditScene::ReLoad() {
}

void CreditScene::SetMousePos(Vector2) {
}

void CreditScene::Push() {
}

void CreditScene::Pull() {
}

void CreditScene::Update() {
}

void CreditScene::Render() {
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(255, 0, 0, 0));

}

void CreditScene::Release() {
}
