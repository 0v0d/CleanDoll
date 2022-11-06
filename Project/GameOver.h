#pragma once
#include "Button.h"

class GameOver
{
private:
	bool _gameOver;
	Vector2 _mousePos;
	Button _retryButton;
	Button _stageSelectButton;
	Vector2 _firstButtonPos;
	Vector2 _secondButtonPos;
	CTexture _retryTexture;
	CTexture _stageSelectTexture;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void Reload();
	void SetGameOver(bool gameOver) { _gameOver = gameOver; }
private:
	void TextureLoad();
	bool IsGameOver() const { return _gameOver; }
};