#pragma once
#include "Mof.h"
class EndTutorialBackGround
{
private:
	CTexture _backGroundTexture;
	Vector2 _pos;
	CRectangle _logRect;

	float _scale;
	bool _fixedScale;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
	bool IsFixedScale() const { return _fixedScale; }

private:
	void LoadTexture();
	void CalcuScale();
	void CalcuPosition();
};