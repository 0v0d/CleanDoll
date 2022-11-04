#pragma once
#include	"Mof.h"

enum class ACCESSORIES_TYPE
{
	DUMP,
	MOP,
	ITEM,
};

class IBaseAccessories
{

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
	virtual void SetPosotion(Vector2 pos) = 0;
	virtual void CalcuScale(float) = 0;
	virtual ACCESSORIES_TYPE GetType() = 0;
};