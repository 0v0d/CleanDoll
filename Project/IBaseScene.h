#pragma once
#include	"Mof.h"
class IBaseScene
{
public:
	virtual void Initialize() = 0;
	virtual void ReLoad() = 0;
	virtual void SetMousePos(Vector2) {}
	virtual void Push() = 0;
	virtual void Pull() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
};