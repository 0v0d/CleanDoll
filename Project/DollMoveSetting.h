#pragma once
#include	"Button.h"
#include	"IBaseSetting.h"
#include    "Slider.h"

class DollMoveSetting:public IBaseSetting
{
	bool* _openAudioSetting;
	
	CTexture _barTexture;
	Vector2  _barPos;
	
	
	CTexture  _baseSelectButtonTexture;
	const int _baseButtonValue = 5;
	Button* _buttonArray = new Button[_baseButtonValue];
	int _baseSpaseCount;
	float _bottonBetweenDistance;

	CTexture  _selectButtonTexture;
	Button   _selectButton;
	Vector2 _selectButtonPos;
	bool _push;

	float _lastSelectButtonPosX;
	
	Button _closeButton;
	Vector2 _mousePos;
	CTexture _closeButtonTexture;
	CSoundBuffer _se;

	float* _factorArray;
	CTexture* _factorTextureArray;
	CTexture _logoTexture;

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
	void LimitMove();
	void CalcuLastPos();
	void SetMethodButton();
};

