#pragma once
#include "Button.h"

class GameClear
{
private:
	CSpriteMotionController _animation;
	const int _menuValue = 2;
	bool _goal;
	bool _remove;
	float _scale;
	Vector2 _mousePos;

	Vector2 _backStageClearPos, _stageClearPos, _nextButtonPos,_stageSelectButtonPos, _retryButtonPos;
	CTexture _backStageClearTexture,_stageClearTecture, _nextStageTexture, _stageSelectTexture, _retryTexture;
	Button _nextStageButton,_stageSelectButton, _retryButton;
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
	void SetAnimation();

};