#pragma once
#include	"Button.h"
#include	"IBaseSetting.h"
#include	"Slider.h"

class DollMoveSetting:public IBaseSetting

{
	bool* _openAudioSetting;
	
	CTexture _barTexture;
	Vector2  _barPos;
	
	
	CTexture  _baseSelectButtonTexture;
	int _baseButtonValue = 5;
	Button* _buttonArray = new Button[_baseButtonValue];
	int _baseSpaseCount=4;
	float _bottonBetweenDistance;

	


	CTexture  _selectButtonTexture;
	Button   _selectButton;
	Vector2    _selectButtonPos;
	bool     _push;

	float _lastSelectButtonPosX;
	
	CTexture _checkBoxTexture,_checkTexture;
	Button   _checkBoxButton,_checkButton;
	bool     _checkBox;

		
	Button _closeButton;
	Vector2 _mousePos;
	CTexture _closeButtonTexture;


	CSoundBuffer _se;



public:
	void Initialize();
	void SetOpenSetting(bool* openSetting) { _openAudioSetting = openSetting; }

	void Update();
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	bool IsCheckBox(){ return _checkBox; }

	void Render();
	void Release();

	
private:
	void LoadTexture();
	float GetFindMovedPos();
	void LimitMove();
	void CalcuLastPos();
};

