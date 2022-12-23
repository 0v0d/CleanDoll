#include "StageSelectLogo.h"

void StageSelectLogo::Initialize() {


}

void StageSelectLogo::Load() {
	StSelectLogoTexture.Load("stageselect.png");
}

void StageSelectLogo::ReLoad() {
	posX = -100;
	posY = 30;
	Alpha = 0;
}

void StageSelectLogo::Update() {
		if (Alpha < 255&&posX<=100) {
			Alpha += 3;
			posX+= 2;
		}
}

void StageSelectLogo::Render() {
	StSelectLogoTexture.RenderScale(posX, posY,1,MOF_ARGB(Alpha,255,255,255));
}

void StageSelectLogo::Release() {
	StSelectLogoTexture.Release();

}