#pragma once
#include	"Mof.h"
#include "SlideInUI.h"

class RemainingIcon
{
	CTexture* _iconTexture;
	CTexture* _markTexture;
	CTexture* _notExistTexture;
	Vector2 _position, _markPosition;
	SlideInUI _slideInUI;
	bool _mark, _notExist;
	float _scale;
public:
	void ReLoad();
	void SetTexture(CTexture*, CTexture*, CTexture*);
	void SetPosition(Vector2);
	void SetScale(float scale);

	void MarkIcon() { _mark = true; }
	void SetNotExistFlg(bool flg) { _notExist = flg; }
	void Render();
	void Update();
private:
	void CalcuMarkPosition();
};
