#include "LetNextStage.h"

void LetNextStage::Initialize()
{
	_mousePos = Vector2(0, 0);
	_button.SetStatu(_pos, _size);
}

void LetNextStage::Render()
{
	_button.Render();
}
void LetNextStage::Release()
{
	
}
void LetNextStage::TextureLoad()
{
	
}