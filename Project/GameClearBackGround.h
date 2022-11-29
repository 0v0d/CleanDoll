#pragma once
#include "Mof.h"
class GameClearBackGround
{
private:
	CTexture _backGroundTexture;
	Vector2 Pos;
	CRectangle _clearLogRect;

	float _scale;
	bool _isFixedScale;//scale�l��1.0���ɂȂ��true�ɂȂ�
public:
	void Initialize();
	void Update();
	void ScaleRender();
	void Release();
	bool IsFixedScale() { return _isFixedScale; }
};

