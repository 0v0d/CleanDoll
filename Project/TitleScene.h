#pragma once
#include	"SceneManager.h"
#include	"IBaseScene.h"
#include	"BackGround.h"
#include    "Mof.h"

class TitleScene :public IBaseScene
{
	BackGround _backGround;
	CTexture _titleBackTexture;
	CRectangle _titleBackRect;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void InputMouseKey();
	void Render();
	void Release();

};