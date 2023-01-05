#pragma once
#include	"Mof.h"
class Button
{
	CTexture* _texture = nullptr;
	Vector2 _centerPos;
	float _scale;
	const float _variableScale = 1.1f;
	CRectangle _hitBox;
	bool _pushButton, _pullButton, _mouseOnButton;

public:
	Button();
	void SetTexture(CTexture* buttonTexture) { _texture = buttonTexture; }
	void SetPosition(Vector2 buttonCenterPosition);
	void CalcuScale(float sizeX,float sizeY);

	void SetMousePos(Vector2 mousePosition);
	void Push();
	void Pull();
	bool IsPushButton() { return _pushButton; }
	bool IsPullButton() { return _pullButton; }

	void Render();
private:
	void CalcuHitBox();
	bool CheckOnMouse(Vector2 mousePosition);
	void SetPullFlg(bool flg) { _pullButton = flg; }
};