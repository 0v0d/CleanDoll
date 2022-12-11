#include "AudioSetting.h"

void AudioSetting::Initialize()
{
	LoadTexture();
	CalcuScale();

	_sliderArray = new Slider[_sliderValue];
	Vector2 _barSize = Vector2(_barTexture.GetWidth(), _barTexture.GetHeight());
	Vector2 _buttonSize = Vector2(_buttonTexture.GetWidth(), _buttonTexture.GetHeight());
	Vector2 _barPos = Vector2(g_pGraphics->GetTargetWidth() / 2 , 300);

	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].SetStatu(Vector2(_barPos.x, _barPos.y * i + 250),&_barTexture, &_buttonTexture, 0.7f, HORIZON);
		_muted[i] = false;
	}
	

	_closeButton.SetTexture(&_closeButtonTexture);
	_closeButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 650));

	for (int i = 0; i < _sliderValue; i++) 
	{
		_audioPos[i] = Vector2(_barPos.x - _barSize.x / 2 - _audioTexture[i].GetWidth() * _audioScale - 10, (_barPos.y * i + 250) + _barSize.y / 2 - _audioTexture[i].GetHeight() * _audioScale / 2);
	}

	_BGMPos = Vector2(_audioPos[0].x - _BGMTexture.GetWidth() * _BGMScale-10, _audioPos[0].y + _audioTexture[0].GetHeight() * _audioScale / 2 - _BGMTexture.GetHeight() * _BGMScale / 2);
	_SEPos = Vector2(_audioPos[1].x - _SETexture.GetWidth() * _SEScale-10, _audioPos[1].y + _audioTexture[1].GetHeight() * _audioScale / 2 - _SETexture.GetHeight() * _SEScale / 2);
}

void AudioSetting::LoadTexture() {
	for (int i = 0; i < _sliderValue; i++) {
		_audioTexture[i].Load("音量マーク.png");
		_mutedTexture[i].Load("speaker_muted.png");
	}
	_closeButtonTexture.Load("戻る　テキスト.png");
	_BGMTexture.Load("BGM 1.png");
	_SETexture.Load("SE 1.png");
	_barTexture.Load("s (1).png");
	_buttonTexture.Load("s (2).png");
}
void AudioSetting::Update()
{
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].Update();
	}
	SetMute();
}

void AudioSetting::CalcuScale() {
	_audioScale = _textureHeight / _audioTexture->GetHeight();
	_BGMScale = _textureHeight / _BGMTexture.GetHeight();
	_SEScale = _textureHeight / _SETexture.GetHeight();
}

void AudioSetting::SetMute() {
	for (int i = 0; i < _sliderValue; i++) {
		if (_sliderArray[i].GetValue() <= 0) {
			_muted[i] = true;
		}
		else {
			_muted[i] = false;
		}
	}
}

void AudioSetting::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	_closeButton.SetMousePos(mousePos);
}

void AudioSetting::Push()
{
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].PushSlider();
	}
	_closeButton.Push();
}

void AudioSetting::Pull()
{
	for (int i = 0; i < _sliderValue; i++)
	{
		_sliderArray[i].PullSlider();
	}

	_closeButton.Pull();
	if (_closeButton.IsPullButton()) {
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

	for (int i = 0; i < _sliderValue; i++) {
		if (!_muted[i]) {
			_audioTexture[i].RenderScale(_audioPos[i].x, _audioPos[i].y, _audioScale);
		}
		if (_muted[i]) {
			_mutedTexture[i].RenderScale(_audioPos[i].x, _audioPos[i].y, _audioScale);
		}
	}
	_BGMTexture.RenderScale(_BGMPos.x, _BGMPos.y, _BGMScale);
	_SETexture.RenderScale(_SEPos.x, _SEPos.y, _SEScale);
}

void AudioSetting::Release()
{
	_closeButtonTexture.Release();
	_barTexture.Release();
	_buttonTexture.Release();
	delete[] _sliderArray;

	for (int i = 0; i < _sliderValue; i++) {
		_audioTexture[i].Release();
		_mutedTexture[i].Release();
	}
	_BGMTexture.Release();
	_SETexture.Release();

	delete[] _audioTexture;
	delete[] _audioPos;
	//for (int i = 0;i < _sliderValue;i++) _sliderArray[i].Release();
}