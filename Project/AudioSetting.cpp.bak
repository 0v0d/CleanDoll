#include "AudioSetting.h"

void AudioSetting::Initialize(){
	_sliderArray = new Slider[_sliderValue];
	Vector2 _barSize = Vector2(500, 20);
	Vector2 _buttonSize = Vector2(50, 80);
	Vector2 _barPos = Vector2(100, 100);
	for (int i = 0;i < _sliderValue;i++) {
		_sliderArray[i].SetBarStatu(_barSize, _buttonSize, _barPos,HORIZON);
	}
_closeButton = CRectangle(g_pGraphics->GetTargetWidth() / 2 - 50, 400, g_pGraphics->GetTargetWidth() / 2 + 50, 450);
}

void AudioSetting::Update(){

}

void AudioSetting::Push(Vector2 mousePos) {
	PushButton(mousePos);
}

void AudioSetting::PushButton(Vector2 mousePos) {
	if (_closeButton.CollisionPoint(mousePos)) {
		*_openAudioSetting = false;
	}
}

void AudioSetting::Render(){
	for (int i = 0;i < _sliderValue;i++) _sliderArray[i].Render();

	CGraphicsUtilities::RenderFillRect(_closeButton, MOF_COLOR_HGREEN);
}

void AudioSetting::Release() {
	//for (int i = 0;i < _sliderValue;i++) _sliderArray[i].Release();
	delete[] _sliderArray;
}