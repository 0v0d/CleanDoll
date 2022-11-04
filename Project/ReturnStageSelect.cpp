#include "ReturnStageSelect.h"
void ReturnStageSelect::Initialize()
{
	_pos = Vector2(200, 500);
	_size = Vector2(200, 120);
	_button.SetStatu(_pos, _size);
}

void ReturnStageSelect::Render()
{
	_button.Render();
}

void ReturnStageSelect::Release()
{
	
}

void ReturnStageSelect::TextureLoad()
{
	
}