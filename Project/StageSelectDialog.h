#pragma once
#include    "Button.h"
#include	"Mof.h"
class StageSelectDialog
{
private:
	Vector2  _Pos;
	Vector2  _YesButtonPos;
	Vector2  _NoButtonPos;
	CTexture _YesTexture;
	CTexture _NoTexture;
	Button  _YesButton;
	Button  _NoButton;
	bool   _OpenStaSeleDia;
public:
	void Initialize();
	void SetYesButton();
	void SetNoButton();
	void Render();
	void Release();
};

