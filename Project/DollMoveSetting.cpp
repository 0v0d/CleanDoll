#include "DollMoveSetting.h"

void DollMoveSetting::Initialize()
{
	LoadTexture();
	_barPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _barTexture.GetWidth() / 2, 350);
	_bottonBetweenDistance = _barTexture.GetWidth() / _baseSpaseCount;
	_selectButtonPos = Vector2(_barPos.x + _bottonBetweenDistance * 2, _barPos.y + _barTexture.GetHeight() / 2);
	
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].SetTexture(&_baseSelectButtonTexture);
		_buttonArray[i].SetPosition(Vector2(_barPos.x + _bottonBetweenDistance * i, _barPos.y+ _barTexture.GetHeight()/2));
	}
	_selectButton.SetTexture(&_selectButtonTexture);
	_selectButton.SetPosition(_selectButtonPos);

	_checkBoxButton.SetTexture(&_checkBoxTexture);
	_checkBoxButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2 , 600));

	_checkButton.SetTexture(&_checkTexture);
	_checkButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 600));

	_closeButton.SetTexture(&_closeButtonTexture);
	_closeButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 870));
	
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
void DollMoveSetting::Update()
{
	if (_push)
	{
		_selectButtonPos.x = _mousePos.x;
		LimitMove();
		_selectButton.SetPosition(_selectButtonPos);
	}
	
}
void DollMoveSetting::LimitMove()
{
	if (_selectButtonPos.x < _barPos.x)
	{
		_selectButtonPos.x = _barPos.x;
	}
	if (_selectButtonPos.x > _barPos.x + _barTexture.GetWidth())
	{
		_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * _baseSpaseCount;
	}
}
float DollMoveSetting::GetFindMovedPos()
{

	if (_selectButtonPos.x <= _mousePos.x)
	{
		for (int i = _baseSpaseCount; i >= 0; i--)
		{
			if (_barPos.x + _bottonBetweenDistance * i <= _mousePos.x)
			{
				_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * i;
				break;
			}

		}
	}
	else if (_selectButtonPos.x >= _mousePos.x)
	{
		for (int i = 0; i <= _baseSpaseCount; i++)
		{
			if (_barPos.x + _bottonBetweenDistance * i >= _mousePos.x)
			{
				 _selectButtonPos.x = _barPos.x + _bottonBetweenDistance * i;
				 break;
			}

		}
	}
		return _selectButtonPos.x;

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
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].Push();
		
	}
	
	_checkBoxButton.Push();
	_checkButton.Push();
	_selectButton.Push();
	if (_selectButton.IsPushButton())
	{
		_push = true;
	}
	_closeButton.Push();
}

void DollMoveSetting::Pull()
{
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].Pull();
		if (_buttonArray[i].IsPullButton())
		{
			_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * i;
			_selectButton.SetPosition(_selectButtonPos);
			break;
		}
	}

	
	_selectButton.Pull();
	if (_selectButton.IsPullButton())
	{
		_push = false;
		_selectButton.SetPosition(Vector2(GetFindMovedPos(), _barPos.y + _barTexture.GetHeight() / 2));
	}
	_checkBoxButton.Pull();
	if (_checkBoxButton.IsPullButton())
	{
		_checkBox = !_checkBox;
	}
	_checkButton.Pull();

	_closeButton.Pull();
	if (_closeButton.IsPullButton()) {
		*_openAudioSetting = false;
	}
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
	
	if (_checkBox)
	{
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

	delete _buttonArray;
	
}