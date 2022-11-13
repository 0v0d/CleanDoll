#pragma once
#include "Button.h"

class GameClear
{
private:
	const int _menuValue = 2;
	bool _goal;
	bool _remove;
	Vector2 _mousePos;
	Vector2 _firstButtonPos;
	Vector2 _secondButtonPos;
	Vector2 _thirdButtonPos;
	Button _nextStageButton;
	Button _stageSelectButton;
	Button _retryButton;
	CTexture _nextStageTexture;
	CTexture _stageSelectTexture;
	CTexture _retryTexture;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetGoal(bool goal){ _goal = goal; }
	void Reload();
	bool IsRemove() { return _remove; }
private:
	void TextureLoad();
	bool IsGoal() const{ return _goal; }
};