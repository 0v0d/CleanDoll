#pragma once
#include "Mof.h"
#include "LetNextStage.h"
#include "ReturnStageSelect.h"
class GameClear
{
private:
	bool _goal;
	Vector2 _mousePos;
	LetNextStage _nextStage;
	ReturnStageSelect _RetrunStageSelect;
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

