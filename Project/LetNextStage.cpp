#include "LetNextStage.h"

void LetNextStage::Initialize()
{
	_pos = Vector2(400, 300);
	_size = Vector2(300, 120);
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