#include "EnergyBar.h"

void EnergyBar::Initialize() {
	_barPosition.x = _basePosition.x;
	_barPosition.y = _basePosition.y;

	float angle = _doublePie / _barValue;
	_rotate = angle * _number * -1;

	int supportToTop = _barValue / 2;
	_rotate += angle * supportToTop;
}

void EnergyBar::Update() {

}

void EnergyBar::Render() {
	_barTexture->RenderScaleRotate(_barPosition.x, _barPosition.y, _scale, _rotate, *_renderColor);
}

void EnergyBar::UsedEnergyRender() {
	_barTexture->RenderScaleRotate(_barPosition.x, _barPosition.y, _scale, _rotate, MOF_COLOR_HBLACK);
}

void EnergyBar::Release() {

}