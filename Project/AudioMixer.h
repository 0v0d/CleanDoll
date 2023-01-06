#pragma once
#include	"Mof.h"
class AudioMixer
{
	static AudioMixer* _instance;
	float _bgmVolume;
	float _seVolume;

	CSoundBuffer* _bgm = nullptr;
	CSoundBuffer* _se = nullptr;
public:

	void SetBgmVolume(float volume);
	void SetSeVolume(float volume);
	void PlayBgm(CSoundBuffer* bgm);
	void PlaySe(CSoundBuffer* se);

	static AudioMixer& Instance() {
		if (_instance == nullptr) _instance = new AudioMixer;
		return *_instance;
	}
};