#include "GameSceneBGM.h"
void GameSceneBGM::Initialize()
{
	_bgm.Load("BGM.mp3");
	_bgm.SetLoop(TRUE);
	_bgm.Play();
}
void GameSceneBGM::Update()
{
	//_bgm.SetVolume();
}
void GameSceneBGM::Release()
{
	_bgm.Release();
}
void GameSceneBGM::Stop()
{
	_bgm.Stop();
	
}
