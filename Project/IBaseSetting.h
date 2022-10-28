#pragma once
#include	"Mof.h"
class IBaseSetting
{

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void SetOpenSetting(bool*) = 0;
	virtual void Push(Vector2 mousePos) = 0;
	virtual void Pull(Vector2 mousePos) = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};