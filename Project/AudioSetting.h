#pragma once
#include "Button.h"
#include	"IBaseSetting.h"
#include	"Slider.h"

class AudioSetting :public IBaseSetting
{
private:
	bool* _openAudioSetting;

	const int _sliderValue = 2;
	Slider* _sliderArray;
	int _BGMVolume, _SEVolume;
	Button _closeButton;
	Vector2 _closeButtonPos;
	CTexture _closeButtonTexture;
	CTexture _buttonTexture;
	CTexture _barTexture;
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