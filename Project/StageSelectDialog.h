#pragma once
#include    "Button.h"
#include	"Mof.h"
class StageSelectDialog
{
private:
	float  _mPosX,_mPosY;
	Vector2  _Pos;
	Vector2  _YesButtonPos;
	Vector2  _NoButtonPos;
	CTexture _YesTexture;
	CTexture _NoTexture;
	Button  _YesButton;
	Button  _NoButton;
	bool  _OpenStaSeleDia;
	int   _clickCount;
	int   _stagenumber;
public:
	void Initialize();
	void SetYesButton();
	void SetNoButton();
	bool CheckYesButton(Vector2 mousePos) { return _YesButton.CheckOnButton(mousePos); }
	bool CheckNoButton(Vector2 mousePos) { return _NoButton.CheckOnButton(mousePos); }
	void CloseDialog(Vector2 mousePos);
	void Push(Vector2 mousePos);
	void Update();
	void Render();
	void Release();
	int GetStageNumber() { return _stagenumber; }
	bool IsOpenStDialog() { return _OpenStaSeleDia; }
	void  SetStageNumber(int stagenumber);
	void ClickCheck(Vector2 mousePos);
};
