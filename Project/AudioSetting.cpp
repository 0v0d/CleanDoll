#include "AudioSetting.h"

void AudioSetting::Initialize()
{
	_sliderArray = new Slider[_sliderValue];
	Vector2 _barSize = Vector2(500, 20);
	Vector2 _buttonSize = Vector2(50, 80);
	Vector2 _barPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _barSize.x / 2, 300);
	_barTexture.Load("s (1).png");
	_buttonTexture.Load("s (2).png");
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].SetStatu(Vector2(_barPos.x, _barPos.y +(i * 170)),&_barTexture, &_buttonTexture, 0.7, HORIZON);
	}
	_closeButtonTexture.Load("戻る　テキスト.png");
	_closeButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _closeButtonTexture.GetWidth()/2 , 600);

	_closeButton.SetStatu(_closeButtonPos, &_closeButtonTexture);
}

void AudioSetting::Update()
{
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].Update();
	}
}

void AudioSetting::Push(Vector2 mousePos)
{
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].PushSlider();
	}
	PushButton(mousePos);
}

void AudioSetting::Pull(Vector2 mousePos)
{
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].PullSlider();
	}
}

void AudioSetting::PushButton(Vector2 mousePos)
{
	if (_closeButton.CheckOnButton(mousePos))
	{
		*_openAudioSetting = false;
	}
}

void AudioSetting::Render()
{
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].Render();
	}
	_closeButton.Render();
}

void AudioSetting::Release()
{
	_closeButtonTexture.Release();
	_barTexture.Release();
	_buttonTexture.Release();
	//for (int i = 0;i < _sliderValue;i++) _sliderArray[i].Release();
	
	delete[] _sliderArray;
}