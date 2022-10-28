#pragma once
#include	"Mof.h"
#include	"AudioSetting.h"
class SetUpSetting{

	bool _openSetting;
	AudioSetting _audioSetting;
public:
	void Initialize();
	void Update();
	void Push(Vector2 mousePos);
	void Render();
	void Release();
};