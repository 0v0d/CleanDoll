#pragma once
#include "Mof.h"
class StageSelectLogo
{
private:
	CTexture _selectLogoTexture;
	Vector2 _pos;
	bool _slidIn;
	int _alpha;
public:
	void Initialize();
	void ReLoad();
	void Update();
	void Render();
	void Release();
private:
	void Load();
};

