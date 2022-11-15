#pragma once
#include	"SceneManager.h"
#include	"IBaseScene.h"
#include	"BackGround.h"
#include    "Mof.h"

class TitleScene :public IBaseScene
{
	BackGround _backGround;
	CTexture _titleBackTexture;
	CTexture _startTexture;
	CRectangle _titleBackRect;
	uint8_t _alpha;
	bool _end;
	float _time;
	const float _increase = 0.003;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void InputMouseKey();
	void Render();
	void Release();
private:
	int CalcSequence(float x);
};