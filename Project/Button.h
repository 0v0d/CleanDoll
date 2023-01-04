#pragma once
#include	"functional"
#include	"Mof.h"
#include	"SE.h"

class Button
{
	CTexture* _texture = nullptr;
	Vector2 _centerPos;
	float _scale;
	const float _variableScale = 1.1f;
	CRectangle _hitBox;
	bool _push, _pull, _mouseOnButton;
	bool _pushCallMethod, _pullCallMethod;

	std::function<void()> _callMethod = nullptr;
 	SE _se;

public:
	Button();

	void SetStatu(bool push, bool pull, std::function<void()> callMethod);
	void SetTexture(CTexture* buttonTexture) { _texture = buttonTexture; }
	void SetSeSound(CSoundBuffer* seSound) { _se.SetSE(seSound); }
	void SetPosition(Vector2 buttonCenterPosition);
	void CalcuScale(float sizeX,float sizeY);

	void SetMousePos(Vector2 mousePosition);
	void Push();
	void Pull();

	void Render();
private:
	void CalcuHitBox();
	bool CheckOnMouse(Vector2 mousePosition);
};