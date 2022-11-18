#include "BarManager.h"
#include "SceneManager.h"

void BarManager::Initialize()
{
	_preview.SetPreviewTexture(_barArray[0].GetPreviewTexture());
}

void BarManager::CreateBarArray(int stageValue)
{
	_stageValue = stageValue;

	_barArray = new Bar[_stageValue];
	for (int i = 0; i < _stageValue; i++)
	{
		_barArray[i].SetStageValue(_stageValue);
	}
}

void BarManager::SetBarStatu(int stageNumber, std::string previewTextureName, std::string stageName, int difficulty, std::string stageDataTextName)
{
	if (_stageValue <= stageNumber || stageNumber < 0) return;

	_barArray[stageNumber].SetStatu(stageNumber, previewTextureName, stageName, difficulty, stageDataTextName);
	_barArray[stageNumber].Initialize();
}


void BarManager::Update()
{

}

void BarManager::PushBar(Vector2 mPos)
{
	for (int i = 0; i < _stageValue; i++)
	{
		if (_barArray[i].CheckOnMouse(mPos) && _barArray[i].IsRenderRange())
		{
			_preview.SetPreviewTexture(_barArray[i].GetPreviewTexture());
			return;
		}
	}
}

void BarManager::PickStage(int bernumber)
{
			_contactFile->LoadStage(_barArray[bernumber].GetStageDataTextName());
			_currentStage = bernumber;
			SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
			return;
}

void BarManager::StartNextStage() {
	_currentStage++;
	if (_currentStage > _stageValue)
	{
		_currentStage = _stageValue;
	}
	_contactFile->LoadStage(_barArray[_currentStage].GetStageDataTextName());
	SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
}

void BarManager::MoveBar(float moveValue)
{
	for (int i = 0; i < _stageValue; i++)
	{
		_barArray[i].Move(moveValue);
	}
}

int BarManager::GetPushBarNumber(Vector2 mousePos) {

	for (int i = 0; i < _stageValue; i++)
	{
		if (_barArray[i].CheckOnMouse(mousePos) && _barArray[i].IsRenderRange())
		{
			return i;
		}
	}
	return -1;
}

void BarManager::Render()
{
	for (int i = 0; i < _stageValue; i++)
	{
		_barArray[i].Render();
	}
	_preview.Render();
}

void BarManager::Release()
{
	for (int i = 0; i < _stageValue; i++)
	{
		_barArray[i].Release();
	}
	delete[] _barArray;
}