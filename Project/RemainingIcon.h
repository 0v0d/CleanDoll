#pragma once
#include	"Mof.h"
class RemainingIcon
{
	CTexture* _iconTexture;
	CTexture* _markTexture;
	CTexture* _notExistTexture;
	Vector2 _position;
	bool _mark, _notExist;
	float _scale;
public:
	void ReLoad();
	void SetTexture(CTexture*, CTexture*, CTexture*);
	void SetPosition(Vector2);
	void SetScale(float scale) { _scale = scale; }

	void MarkIcon() { _mark = true; }
	void NotExistIcon() { _notExist = true; }
	void Render();
};