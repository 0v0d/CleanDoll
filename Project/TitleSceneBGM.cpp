#include "TitleSceneBGM.h"
void TitleSceneBGM::Initialize()
{
	_bgm.Load("BGM.mp3");
	_bgm.SetLoop(TRUE);
	_bgm.Play();
}

void TitleSceneBGM::Update()
{
	//_bgm.SetVolume();
}

void TitleSceneBGM::Stop()
{
	_bgm.Stop();
}


void TitleSceneBGM::Release()
{
	_bgm.Release();
}