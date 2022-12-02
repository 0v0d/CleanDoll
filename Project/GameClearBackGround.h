#pragma once
#include "Mof.h"
class GameClearBackGround
{
private:
	CTexture _backGroundTexture;
	Vector2 _pos;
	CRectangle _clearLogRect;

	float _scale;
	bool _fixedScale;//scale�l��1.0���ɂȂ��true�ɂȂ�
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
	bool IsFixedScale() { return _fixedScale; }

private:
	void LoadTexture();
	void CalcuScale();
	void CalcuPosition();
};

