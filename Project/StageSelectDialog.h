#pragma once
#include    "Button.h"
#include	"Mof.h"
#include	"functional"

class StageSelectDialog
{
	Vector2 _basePos;
	Vector2 _mousePos;
	CTexture _backTexture;
	CTexture _yesTexture,_noTexture;
	Button  _yesButton, _noButton;
	const float _space = 100;
	const float _backScale = 0.95f;
	bool  _openStaSeleDialog;
	int   _clickCount;
	int   _pickStageNumber;

	std::function<void(int)> _loadStageMethod;

public:
	void Initialize();
	void ReLoad();
	void SetLoadStageMethod(std::function<void(int)> method) { _loadStageMethod = method; }

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void SetStageNumber(int stagenumber);

	void Render();
	void Release();

	int GetStageNumber() { return _pickStageNumber; }
	bool IsOpenDialog() { return _openStaSeleDialog; }

private:
	void LoadTexture();
	void CreateButton(Button*, Vector2 pos, CTexture*);
};
