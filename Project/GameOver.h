#pragma once
#include "LetNextStage.h"
#include "RetryGame.h"
#include "ReturnStageSelect.h"

class GameOver
{
private:
	bool _goal;
	Vector2 _mousePos;
	LetNextStage _nextStage;
	ReturnStageSelect _RetrunStageSelect;
	RetryGame _retryGame;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	void SetGoal(bool goal) { _goal = goal; }
	void Reload();
private:
	void TextureLoad();
	bool IsGoal() const { return _goal; }
};

