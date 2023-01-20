#pragma once
#include	"IBaseScene.h"
#include	"BarManager.h"
#include	"Slider.h"
#include	"StageSelectDialog.h"
#include	"MoveBackGround.h"
#include	"BGM.h"
#include	"CreateField.h"
#include	"ContactFile.h"
#include "StageSelectLogo.h"


class StageSelectScene :public IBaseScene
{
private:
	CreateField _createField;
	ContactFile _contactFile;

	StageSelectLogo	_LogoSlide;

	BarManager _barManager;
	StageSelectDialog _stageSelectDialog;
	Preview _preview;
	CTexture _backGroundTexture;
	MoveBackGround _backGround;
	CSoundBuffer _music;

	Vector2 _mousePos;

public:
	void Initialize();
	void CreateTutorialField();
	void ReLoad();
	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void StartNextStage();
	void StageClear();
	void GetCoin();

	void Render();
	void Release();

	CreateField* GetCreateField() { return &_createField; }
	CSoundBuffer* GetBGM() { return &_music; }
private:
	void LoadTexture();
	void LaodSound();
	void LoadStage(int stageNumber);
};