#pragma once
#include <string>

#include	"Mof.h"
class BGM
{
private:
	CSoundBuffer* _bgm;
public:
	void SetBGM(CSoundBuffer* bgm,bool loop);
	void ReLoad();
	void SetVolume(float volume);
	void Stop();
};

