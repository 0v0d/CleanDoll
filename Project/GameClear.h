#pragma once
#include "Button.h"
#include "GameClearLogoAnimation.h"
#include "GameClearBackGround.h"


class GameClear
{
private:
	GameClearLogoAnimation _gameClearAnim;
	GameClearBackGround _clearBackGround;
	const int _menuValue = 2;
	bool _goal;
	bool _remove;
	float _scale;
	Vector2 _mousePos;

	Vector2  _nextButtonPos,_stageSelectButtonPos, _retryButtonPos;
	CTexture _nextStageTexture, _stageSelectTexture, _retryTexture;
	Button _nextStageButton,_stageSelectButton, _retryButton;
	
	Vector2 _backStageClearPos;
	CTexture _backStageClearTexture;
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