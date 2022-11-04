#include "LetNextStage.h"

void LetNextStage::Initialize()
{
	_pos = Vector2(200, 300);
	_size = Vector2(200, 120);
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