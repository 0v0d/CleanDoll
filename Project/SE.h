#pragma once
#include	"Mof.h"
class SE
{
	CSoundBuffer* _se;
public:
	void SetSE(CSoundBuffer* se) { _se = se; }
	void Play();
	void SetVolume(float volume);
	void Stop();
};