#include "DollMoveSetting.h"

void DollMoveSetting::Initialize()
{
	LoadTexture();
	_buttonArray = new Button[_baseButtonValue];

	_barPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _barTexture.GetWidth() / 2, 350);
	
	const int _baseSpaseCount = _baseButtonValue - 1;
	_buttonSpase = _barTexture.GetWidth() / _baseSpaseCount;
	_selectButtonPos = Vector2(_barPos.x + _buttonSpase * 2, _barPos.y + _barTexture.GetHeight() / 2);
	
	CreateButton();
	_checkBox = false;
}

void DollMoveSetting::LoadTexture() 
{
	_barTexture.Load("dollbar.png");
	_baseSelectButtonTexture.Load("非選択.png");
	_selectButtonTexture.Load("選択.png");
	_checkBoxTexture.Load("チェックボックス.png");
	_checkTexture.Load("チェック.png");
	_closeButtonTexture.Load("戻る　テキスト.png");
}

void DollMoveSetting::CreateButton() {
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].SetTexture(&_baseSelectButtonTexture);
		_buttonArray[i].SetPosition(Vector2(_barPos.x + _buttonSpase * i, _barPos.y + _barTexture.GetHeight() / 2));
	}
	_selectButton.SetTexture(&_selectButtonTexture);
	_selectButton.SetPosition(_selectButtonPos);

	_checkBoxButton.SetTexture(&_checkBoxTexture);
	_checkBoxButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 600));

	_checkButton.SetTexture(&_checkTexture);
	_checkButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 600));

	_closeButton.SetTexture(&_closeButtonTexture);
	_closeButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 870));
}


void DollMoveSetting::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].SetMousePos(mousePos);
	}
	_selectButton.SetMousePos(mousePos);
	_checkBoxButton.SetMousePos(mousePos);
	_checkButton.SetMousePos(mousePos);
	_closeButton.SetMousePos(mousePos);
}

void DollMoveSetting::Push()
{
	for (int i = 0; i < _baseButtonValue; i++){
		_buttonArray[i].Push();
	}

	//黒丸移動
	if(CheckMouseCollisionBar()){
		_selectButton.SetPosition(Vector2(GetFindMovedPosX(), _barPos.y + _barTexture.GetHeight() / 2));
	}
	
	_checkBoxButton.Push();
	_checkButton.Push();
	_selectButton.Push();
	
	_closeButton.Push();
}

void DollMoveSetting::Pull()
{
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].Pull();
	}

	_selectButton.Pull();
	_checkBoxButton.Pull();
	if (_checkBoxButton.IsPullButton())
	{
		_checkBox = !_checkBox;
	}
	_checkButton.Pull();

	_closeButton.Pull();
	if (_closeButton.IsPullButton()) {
		*_openDollMoveSetting = false;
	}
}

float DollMoveSetting::GetFindMovedPosX()
{
	const int pushSupSpace = 40;
	for (int i = _baseButtonValue - 1; i >= 0; i--)
	{
		if (_barPos.x + _buttonSpase * i - _baseSelectButtonTexture.GetWidth() / 2 - pushSupSpace < _mousePos.x)
		{
			_selectButtonPos.x = _barPos.x + _buttonSpase * i;
			break;
		}
	}

	return _selectButtonPos.x;
}

bool DollMoveSetting::CheckMouseCollisionBar() {
	const int supSpaceY = 10;
	return _mousePos.x >= _barPos.x - _baseSelectButtonTexture.GetWidth() / 2 && _mousePos.x <= _barPos.x + _barTexture.GetWidth() + _baseSelectButtonTexture.GetWidth() / 2 &&
		_mousePos.y >= _barPos.y - _baseSelectButtonTexture.GetHeight() / 2 - supSpaceY && _mousePos.y <= _barPos.y + _barTexture.GetHeight() + _baseSelectButtonTexture.GetHeight() / 2 + supSpaceY;
}


void DollMoveSetting::Render()
{
	_barTexture.Render(_barPos.x,_barPos.y);
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].Render();
	}
	_closeButton.Render();
	_selectButton.Render();
	_checkBoxButton.Render();
	
	if (_checkBox){
		_checkButton.Render();
	}
}

void DollMoveSetting::Release()
{
	_baseSelectButtonTexture.Release();
	_selectButtonTexture.Release();
	_barTexture.Release();
	_closeButtonTexture.Release();
	_checkBoxTexture.Release();
	_checkTexture.Release();
	
	delete[] _buttonArray;
}