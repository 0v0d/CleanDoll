#pragma once
#include	"IBaseScene.h"
#include	"BarManager.h"
#include	"Slider.h"
#include	"StageSelectDialog.h"
#include	"BackGround.h"
#include	"CreateField.h"
#include	"ContactFile.h"

class StageSelectScene :public IBaseScene
{
private:
	CreateField _createField;
	ContactFile _contactFile;

	BarManager _barManager;
	StageSelectDialog _stageSelectDialog;
	Preview _preview;
	CTexture _backGroundTexture;
	BackGround _backGround;

	Vector2 _mousePos;

public:
	void Initialize();
	void ReLoad();
	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void StartNextStage();
	void StageClear();
	void Render();
	void Release();

	CreateField* GetCreateField() { return &_createField; }
private:
	void LoadTexture();
	void LoadStage(int stageNumber);
};