#pragma once
#include	"Button.h"
#include	"IBaseSetting.h"
#include	"Slider.h"
class DollMoveSetting:public IBaseSetting
{
	bool* _openAudioSetting;
	
	
	
	
	Button _closeButton;
	Vector2 _mousePos;
	CTexture _closeButtonTexture;
	


	const float _textureHeight = 50;

public:
	void Initialize();
	void SetOpenSetting(bool* openSetting) { _openAudioSetting = openSetting; }

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	

	void Render();
	void Release();

	
private:
	void LoadTexture();
	void CalcuScale();
};

