#pragma once
#include	"Button.h"
#include	"IBaseSetting.h"
#include	"Slider.h"

class AudioSetting :public IBaseSetting
{
	bool* _openAudioSetting;
	bool* _muted = new bool[_sliderValue];
	const int _sliderValue = 2;
	Slider* _sliderArray;
	int _BGMVolume, _SEVolume;
	Button _closeButton;
	Vector2 _closeButtonPos;
	CTexture _closeButtonTexture;
	CTexture _buttonTexture;
	CTexture _barTexture;
	CTexture* _audioTexture = new CTexture[_sliderValue];
	CTexture* _mutedTexture = new CTexture[_sliderValue];
	Vector2* _audioPos = new Vector2[_sliderValue];

	CTexture _BGMTexture, _SETexture;
	Vector2 _BGMPos, _SEPos;
	const float _textureHeight = 50;
	float _audioScale, _BGMScale, _SEScale;
public:
	void Initialize();
	void SetOpenSetting(bool* openSetting) { _openAudioSetting = openSetting; }
	void Update();
	void Push(Vector2 mousePos);
	void Pull(Vector2 mousePos);
	int GetBGMVolume() { return _BGMVolume; }
	int GetSEVolume() { return _SEVolume; }
	void GetVolume();
	void Render();
	void Release();
private:
	void PushButton(Vector2 mousePos);
	void LoadTexture();
	void CalcuScale();
};