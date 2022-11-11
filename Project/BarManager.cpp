#include "BarManager.h"
#include "SceneManager.h"

void BarManager::Initialize()
{
	LoadTexture();
	_preview.SetPreviewTexture(_barArray->GetPreviewTexture());

	_space = 300;
	CalcuScale();

	_basePosition = Vector2(50, g_pGraphics->GetTargetHeight() / 2 - _baseTexture.GetHeight() / 2);

	for (int i = 0; i < _stageValue; i++) {
		_barArray[i].SetStatu(_baseBarScale, _space);
		_barArray[i].SetBaseBarTexture(&_baseDirtyBarTexture);
		_barArray[i].SetBaseStatu(_basePosition, Vector2(_baseTexture.GetWidth(), _baseTexture.GetHeight()));
		_barArray[i].Initialize();
	}

	_slider.SetStatu(Vector2(_basePosition.x + _baseTexture.GetWidth() - _space * _baseBarScale, _basePosition.y + _baseTexture.GetHeight() / 2)
		, &_barTexture, &_buttonTexture, 0, VERTICAL);
}

void BarManager::ReLoad() {
	for (int i = 0; i < _stageValue; i++) {
		_barArray[i].ReLoad();
	}
}

void BarManager::LoadTexture() {
	_baseTexture.Load("stageselect_base.png");
	_baseCleanBarTexture.Load("BaseCleanBar.png");
	_baseDirtyBarTexture.Load("BaseDirtyBar.png");
	_barTexture.Load("スクロールバー1.png");
	_buttonTexture.Load("スクロールバー2.png");
}

void BarManager::CalcuScale() {
	_baseBarScale = _baseTexture.GetHeight() / (float)((_baseCleanBarTexture.GetHeight() + _space) * 4);
}

void BarManager::CreateBarArray(int stageValue)
{
	_stageValue = stageValue;
	_barArray = new Bar[_stageValue];
}

void BarManager::SetBarStatu(int stageNumber, std::string previewTextureName, std::string barTextureName, int difficulty, std::string stageDataTextName)
{
	if (_stageValue <= stageNumber || stageNumber < 0) return;

	_barArray[stageNumber].SetStageValue(_stageValue);
	_barArray[stageNumber].SetData(stageNumber, previewTextureName, barTextureName, difficulty, stageDataTextName);
}

void BarManager::Update()
{
	_slider.Update();
	MoveBar(_slider.GetValue());
}

void BarManager::Push(Vector2 mPos)
{
	for (int i = 0; i < _stageValue; i++)
	{
		if (_barArray[i].CheckOnMouse(mPos) && _barArray[i].IsRenderRange())
		{
			_preview.SetPreviewTexture(_barArray[i].GetPreviewTexture());
			break;
		}
	}

	_slider.PushSlider();
}

void BarManager::Pull(Vector2 mPos)
{
	_slider.PullSlider();
}

void BarManager::PickStage(Vector2 mPos)
{
	for (int i = 0; i < _stageValue; i++)
	{
		if (_barArray[i].CheckOnMouse(mPos) && _barArray[i].IsRenderRange())
		{
			_contactFile->LoadStage(_barArray[i].GetStageDataTextName());
			_currentStage = i;
			SceneManager::Instance().ChangeScene(SCENE_TYPE::GAME);
			return;
		}
	}
}

void BarManager::StartNextStage() {
	_currentStage++;
	if (_currentStage > _stageValue)_currentStage = _stageValue;
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

void BarManager::Render()
{
	_baseTexture.Render(_basePosition.x, _basePosition.y);
	for (int i = 0; i < _stageValue; i++)
	{
		_barArray[i].Render();
	}
	_preview.Render();
	_slider.Render();
}

void BarManager::Release()
{
	for (int i = 0; i < _stageValue; i++)
	{
		_barArray[i].Release();
	}
	delete[] _barArray;

	_baseTexture.Release();
	_baseCleanBarTexture.Release();
	_baseDirtyBarTexture.Release();
	_barTexture.Release();
	_buttonTexture.Release();
}