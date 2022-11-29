#include "StageSelectSceneBGM.h"
void StageSelectSceneBGM::Initialize()
{
	_bgm.Load("BGM.mp3");
	_bgm.SetLoop(TRUE);
	_bgm.Play();
}

void StageSelectSceneBGM::Update()
{
	//_bgm.SetVolume();
}

void StageSelectSceneBGM::Stop()
{
	_bgm.Stop();
}


void StageSelectSceneBGM::Release()
{
	_bgm.Release();
}