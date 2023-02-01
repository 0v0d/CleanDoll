#pragma once
#include "Button.h"
#include "IBaseScene.h"

class CreditScene :public IBaseScene
{
	CSoundBuffer _music;
	CSoundBuffer _buttonSe;
	CTexture _buttonTexture;
	Button _titleButton;
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
private:
	void LoadTexture();
	void LoadSound();
};

