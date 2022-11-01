#pragma once
#include	"IBaseScene.h"

class TitleScene :public IBaseScene
{
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
};