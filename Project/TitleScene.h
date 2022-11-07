#pragma once
#include	"SceneManager.h"
#include	"IBaseScene.h"
#include    "Mof.h"

class TitleScene :public IBaseScene
{
	CTexture _titleBackTexture;
	CRectangle _titleBackRect;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void InputMouseKey();
	void Render();
	void Release();
private:
	void Load();
};