#pragma once
#include "Button.h"
class ExitGame
{
private:
	CTexture	 _yesTexture, _noTexture;
	Button		 _yesButton, _noButton;
	const float	 _space = 100;
	bool		 _openExitDialog;
	CSoundBuffer _buttonSe;
public:
	void Initialize();

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void OpenExitDialog() { _openExitDialog = true; }

	void Render();
	void Release();

	bool IsOpenExitDialog() { return _openExitDialog; }

private:
	void LoadTexture();
	void CreateButton(Button*, Vector2 pos, CTexture* ,std::function<void()> callMethod);

};