#pragma once
#include	"Mof.h"

class DollOnEnergyVessels
{
private:
	CTexture _facialExpressionTexture;
	Vector2 _facePosition;
	//ï\èÓÇÃêî
	int _facialExpressionValue;
	float renderRectSizeX;
	float _scale;
	CRectangle _renderRect;

public:
	void Initialize();
	void LoadTexture();
	void SetScale(float scale) { _scale = scale; }
	void SetPosition(Vector2 vesselsCenterPosition);
	void SetFacialExpressionValue(int value);
	void Update() {}
	void ChangeFaceEzpression(int facialExpressionNumber);
	void Render();
	void Release();
};