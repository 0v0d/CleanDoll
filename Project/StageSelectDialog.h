#pragma once
#include    "Button.h"
#include	"Mof.h"

class StageSelectDialog
{
	Vector2  _basePos;
	CTexture _backTexture;
	CTexture _yesTexture,_noTexture;
	Button  _yesButton, _noButton;
	const float _space = 100;

	bool  _openStaSeleDialog, _pushYesButton;
	int   _clickCount;
	int   _pickStageNumber;

public:
	void Initialize();
	void ReLoad();

	void Update();
	void Push(Vector2 mousePos);
	void SetStageNumber(int stagenumber);

	void Render();
	void Release();

	int GetStageNumber() { return _pickStageNumber; }
	bool IsOpenStDialog() { return _openStaSeleDialog; }
	bool CheckPushYesButton() { return _pushYesButton; }

private:
	void LoadTexture();
	void CreateButton(Button*, Vector2 pos, CTexture*);
};
