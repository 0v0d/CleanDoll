#include "RetryGame.h"
void RetryGame::Initialize()
{
	_pos = Vector2(400, 500);
	_size = Vector2(300, 120);
	_button.SetStatu(_pos, _size);
}

void  RetryGame::ClickButton(Vector2 mousePos)
{
	if(_button.CheckOnButton(mousePos))
	{
		//もう一度プレイ
		//どうもう一度プレイする関数を呼ぶか
	}
}

void RetryGame::Render()
{
	_button.Render();
}

void RetryGame::Release()
{
	
}