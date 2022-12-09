#pragma once
#include "Button.h"
class ExitGame
{
private:
	Vector2		 _basePos;
	CTexture	 _yesTexture, _noTexture;
	Button		 _yesButton, _noButton;
	const float	 _space = 100;
	bool		 _openExitDialog;
public:
	void Initialize();
	void Update();
	void Push(Vector2 mousePos);
	void Render();
	void Release();
	bool IsOpenExitDialog() { return _openExitDialog; }

	void OpenExitDialog() { _openExitDialog = true; }
	void LoadTExture();
	void CreateButton(Button*, Vector2 pos, CTexture*);

};