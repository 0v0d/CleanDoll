#include "LetNextStage.h"

void LetNextStage::Initialize()
{
	_pos = Vector2(400, 300);
	_size = Vector2(300, 120);
	_button.SetStatu(_pos, _size);
}

void LetNextStage::ClickButton(Vector2 mousePos)
{
	if (_button.CheckOnButton(mousePos))
	{
		//次のステージへ
	}
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