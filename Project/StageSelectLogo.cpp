#include "StageSelectLogo.h"

void StageSelectLogo::Initialize() {
	Load();
}

void StageSelectLogo::Load() {
	_selectLogoTexture.Load("stageselectlogo.png");
}

void StageSelectLogo::ReLoad() {
	_pos.x = -200;
	_pos.y = 10;
	_alpha = 0;
}

void StageSelectLogo::Update() {
	if (_alpha < 255 && _pos.x <= 0) {
		_alpha += 3;
		_pos.x += 2;
	}
}

void StageSelectLogo::Render() {
	_selectLogoTexture.Render(_pos.x, _pos.y,MOF_ARGB(_alpha,255,255,255));
}

void StageSelectLogo::Release() {
	_selectLogoTexture.Release();
}