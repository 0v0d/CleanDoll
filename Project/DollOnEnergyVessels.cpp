#include "DollOnEnergyVessels.h"

void DollOnEnergyVessels::Initialize() {

}

void DollOnEnergyVessels::LoadTexture() {
	_facialExpressionTexture.Load("facial.png");
}

void DollOnEnergyVessels::SetPosition(Vector2 vesselsCenterPosition) {
	const int space = 20;

	_facePosition.x = vesselsCenterPosition.x - _facialExpressionTexture.GetWidth() / _facialExpressionValue * _scale / 2;
	_facePosition.y = vesselsCenterPosition.y - _facialExpressionTexture.GetHeight() * _scale / 2 + space;
}

void DollOnEnergyVessels::SetFacialExpressionValue(int value) {
	_facialExpressionValue = value; 

	renderRectSizeX = _facialExpressionTexture.GetWidth() / _facialExpressionValue;
}

void DollOnEnergyVessels::ChangeFaceEzpression(int facialExpressionNumber) {

	_renderRect = CRectangle(renderRectSizeX * facialExpressionNumber, 0,renderRectSizeX * (facialExpressionNumber + 1), _facialExpressionTexture.GetHeight());
}

void DollOnEnergyVessels::Render() {
	_facialExpressionTexture.RenderScale(_facePosition.x, _facePosition.y, _scale,_renderRect);
}

void DollOnEnergyVessels::Release() {

	_facialExpressionTexture.Release();
}