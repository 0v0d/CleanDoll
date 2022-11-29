#pragma once
#include "Mof.h"
class GameClearBackGround
{
private:
	CTexture _backGroundTexture;
	Vector2 Pos;
	CRectangle _clearLogRect;

	float _scale;
	bool _isFixedScale;//scale’l‚ª1.0‚†‚É‚È‚ê‚Îtrue‚É‚È‚é
public:
	void Initialize();
	void Update();
	void ScaleRender();
	void Release();
	bool IsFixedScale() { return _isFixedScale; }
};

