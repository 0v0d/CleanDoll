#pragma once
#include	"SceneManager.h"
#include	"IBaseScene.h"
#include    "Mof.h"

class TitleScene :public IBaseScene
{
public:
	void Initialize();
	void ReLoad();
	void Update();
	void InputMouseKey();
	void Render();
	void Release();
};