#pragma once
#include "Button.h"

class GameClear
{
private:
	const int _menuValue = 2;
	bool _goal;
	Vector2 _mousePos;
	Vector2 _firstButtonPos;
	Vector2 _secondButtonPos;
	Button _nextStageButton;
	Button _stageSelectButton;
	CTexture _nextStageTexture;
	CTexture _stageSelectTexture;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetGoal(bool goal){ _goal = goal; }
	void Reload();
private:
	void TextureLoad();
	bool IsGoal() const{ return _goal; }
};