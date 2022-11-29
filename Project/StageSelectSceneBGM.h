#pragma once
#include "Mof.h"
class StageSelectSceneBGM
{
private:
	CSoundBuffer _bgm;
public:
	void Initialize();
	void Update();
	void Release();
	void Stop();
};