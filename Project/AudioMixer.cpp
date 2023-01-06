#include "AudioMixer.h"

AudioMixer* AudioMixer::_instance = nullptr;

void AudioMixer::SetBgmVolume(float volume) {
	_bgmVolume = volume;
	_bgm->SetVolume(volume);
}

void AudioMixer::SetSeVolume(float volume) {
	_seVolume = volume; 
}

void AudioMixer::PlayBgm(CSoundBuffer* bgm) {
	if (_bgm != nullptr)_bgm->Stop();
	_bgm = bgm;
	_bgm->SetLoop(true);
	_bgm->SetVolume(_bgmVolume);
	_bgm->Play();
}

void AudioMixer::PlaySe(CSoundBuffer* se) {
	_se = se;
	_se->SetLoop(false);
	_se->SetVolume(_seVolume);
	_se->Play();
}