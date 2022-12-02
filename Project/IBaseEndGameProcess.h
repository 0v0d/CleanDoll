#pragma once
#include	"Mof.h"
class IBaseEndGameProcess
{

public:
	virtual void Update() = 0;
	virtual void SetMousePos(Vector2) = 0;
	virtual void Push() = 0;
	virtual void Pull() = 0;
	virtual void Render() = 0;
};