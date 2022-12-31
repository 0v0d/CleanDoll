#pragma once
#include	"Button.h"
#include	"IBaseSetting.h"
#include	"Slider.h"
class DollMoveSetting:public IBaseSetting
{
	bool* _openDollMoveSetting;
	
	CTexture _barTexture;
	Vector2  _barPos;
	
	CTexture  _baseSelectButtonTexture;
	const int _baseButtonValue = 5;
	Button* _buttonArray;
	float _buttonSpase;

	CTexture  _selectButtonTexture;
	Button   _selectButton;
	Vector2    _selectButtonPos;
	
	CTexture _checkBoxTexture,_checkTexture;
	Button   _checkBoxButton,_checkButton;
	bool     _checkBox;
		
	Button _closeButton;
	Vector2 _mousePos;
	CTexture _closeButtonTexture;

public:
	void Initialize();
	void SetOpenSetting(bool* openSetting) { _openDollMoveSetting = openSetting; }

	void Update() {}
	void SetMousePos(Vector2);
	void Push();
	void Pull();
	bool IsCheckBox(){ return _checkBox; }

	void Render();
	void Release();
	
private:
	void LoadTexture();
	void CreateButton();
	float GetFindMovedPosX();
	bool CheckMouseCollisionBar();
};

