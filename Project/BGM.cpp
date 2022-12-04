#include "BGM.h"

void BGM::SetBGM(CSoundBuffer* bgm, bool loop)
{
	_bgm = bgm;
	_bgm->SetLoop(loop);
	
}

void BGM::Play ()
{
	_bgm->Play();
}

void BGM::SetVolume(float volume)
{
	_bgm->SetVolume(volume);
}

void BGM::Stop()
{
	_bgm->Stop();
}
