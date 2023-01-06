#pragma once
class IBaseSound
{
protected:
	int _bgmVolume;
	int _seVolume;
public:
	void ChangeBgmVolume(int volume) {
		_bgmVolume = volume;
	}
	void ChangeSeVolume(int volume) {
		_seVolume = volume;
	}
};