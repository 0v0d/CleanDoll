#include "ReturnStageSelect.h"
void ReturnStageSelect::Initialize()
{
	_pos = Vector2(400, 500);
	_size = Vector2(300, 120);
	_button.SetStatu(_pos, _size);
}

void  ReturnStageSelect::ClickButton(Vector2 mousePos)
{
	if (_button.CheckOnButton(mousePos))
	{
		SceneManager::Instance().ChangeScene(SCENE_TYPE::STAGESELECT);
	}
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