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
		//������x�v���C
		//�ǂ�������x�v���C����֐����ĂԂ�
	}
}

void RetryGame::Render()
{
	_button.Render();
}

void RetryGame::Release()
{
	
}