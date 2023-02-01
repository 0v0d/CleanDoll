#pragma once
#include "Button.h"
class ExitGame
{
private:
	CTexture _yesTexture, _noTexture;
	Button _yesButton, _noButton;
	CTexture _exitDialogTexture;
	bool _openExitDialog;
	CSoundBuffer _buttonSe;
	const float _backScale = 0.95f;
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
	void LaodSound();
	void CreateButton(Button*, Vector2 pos, CTexture* ,std::function<void()> callMethod);

};