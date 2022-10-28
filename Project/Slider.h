#pragma once
#include	"Mof.h"

enum DRECTION_TYPE
{
	HORIZON,
	VERTICAL
};

class  Slider
{
private:
	//サイズ関係
	Vector2 _barSize;
	Vector2 _buttonSize;
	//座標関係
	Vector2 _barPos;
	Vector2 _buttonPos;
	Vector2 _halfButtonSize;
	Vector2 _halfBarSize;
	//当たり判定
	CRectangle _barRect;
	CRectangle _buttonRect;
	CTexture _barTexture;
	CTexture _buttonTexture;
	DRECTION_TYPE _drectionType;
	bool _onClick;
	const float _half = 0.5;
	const int _maxValue = 100;
	float _moveValue;
	const float _iniPos = 0.7;
	const float _wheelSensitivity = 40;
public:
	void PushSlider(Vector2 mousepos);
	void PullSlider();

	void ClickSlider(Vector2 mousePos);
	void SetBarStatu(Vector2 barSize, Vector2 buttonSize, Vector2 barPos, DRECTION_TYPE drectionType);
	void Update();
	void Render();
	float GetMoveValue() { return _moveValue; }
	void MouseWheelMove(float moveWheel);
private:
	void Move(Vector2 mousePos);
	bool IsClick() { return _onClick; }
	bool CheckClickButton(Vector2 mousePos) { return _buttonRect.CollisionPoint(mousePos); }
	bool CheckClickBar(Vector2 mousePos) { return _barRect.CollisionPoint(mousePos); }
	void SetClick(bool flg) { _onClick = flg; }
};