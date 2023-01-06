#pragma once
#include	"Mof.h"
#include	"IBaseSound.h"
class SE:public IBaseSound
{
	CSoundBuffer* _se;

public:
	void SetSE(CSoundBuffer* se) { _se = se; }
	void Play();
	void Stop();
};