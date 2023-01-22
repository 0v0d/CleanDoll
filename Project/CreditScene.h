#pragma once
#include "IBaseScene.h"

class CreditScene :public IBaseScene
{
	CSoundBuffer _music;
public:
	void Initialize();
	void ReLoad();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	void Update();
	void Render();
	void Release();
	CSoundBuffer* GetBGM() { return &_music; }
};

