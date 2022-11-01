#pragma once
#include	"IBaseSetting.h"
#include	"Slider.h"
class AudioSetting :public IBaseSetting
{
	bool* _openAudioSetting;
	CRectangle _closeButton;

	const int _sliderValue = 2;
	Slider* _sliderArray;
	int _BGMVolume, _SEVolume;

public:
	void Initialize();
	void SetOpenSetting(bool* openSetting) { _openAudioSetting = openSetting; }
	void Update();
	void Push(Vector2 mousePos);
	void Pull(Vector2 mousePos);
	int GetBGMVolume() { return _BGMVolume; }
	int GetSEVolume() { return _SEVolume; }

	void Render();
	void Release();

private:
	void PushButton(Vector2 mousePos);
};