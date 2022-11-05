#include "AudioSetting.h"

void AudioSetting::Initialize()
{
	_sliderArray = new Slider[_sliderValue];
	Vector2 _barSize = Vector2(500, 20);
	Vector2 _buttonSize = Vector2(50, 80);
	Vector2 _barPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _barSize.x / 2, 300);

	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].SetStatu(Vector2(_barPos.x, _barPos.y * i + 60),_barSize, _buttonSize, 0.7, HORIZON);
	}
	_closeButtonPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - 50, 400);
	_closeButtonTexture.Load("戻る　テキスト.png");
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
	//for (int i = 0;i < _sliderValue;i++) _sliderArray[i].Release();
	
	delete[] _sliderArray;
}