#pragma once
#include	"Mof.h"
#include	"Field.h"

class InputInGame
{
	Field* _field;
	Vector2 _mousePosition;
public:
	void SetField(Field* field) { _field = field; }
	void Update();

private:
	void InputKey();
	void InputMouse();

	void PassedBlock();
};