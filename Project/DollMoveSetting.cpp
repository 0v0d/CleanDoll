#include "DollMoveSetting.h"

void DollMoveSetting::Initialize()
{
	LoadTexture();
	_barPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _barTexture.GetWidth() / 2, 350);
	_bottonBetweenDistance = _barTexture.GetWidth() / _baseSpaseCount;
	
	//���Ԗڂ�
	int initButtonNumber = 1;
	_selectButtonPos = Vector2(_barPos.x + _bottonBetweenDistance * initButtonNumber, _barPos.y + _barTexture.GetHeight() / 2);
	_lastSelectButtonPosX = _barPos.x + _bottonBetweenDistance * initButtonNumber;
	
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].SetTexture(&_baseSelectButtonTexture);
		_buttonArray[i].SetPosition(Vector2(_barPos.x + _bottonBetweenDistance * i, _barPos.y+ _barTexture.GetHeight()/2));
		_buttonArray[i].SetSeSound(&_se);
	}

	_buttonArray[0].SetStatu(false, true, [&]() {_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 0;_selectButton.SetPosition(_selectButtonPos); });
	_buttonArray[1].SetStatu(false, true, [&]() {_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 1;_selectButton.SetPosition(_selectButtonPos); });
	_buttonArray[2].SetStatu(false, true, [&]() {_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 2;_selectButton.SetPosition(_selectButtonPos); });
	_buttonArray[3].SetStatu(false, true, [&]() {_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 3;_selectButton.SetPosition(_selectButtonPos); });
	_buttonArray[4].SetStatu(false, true, [&]() {_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 4;_selectButton.SetPosition(_selectButtonPos); });

	_selectButton.SetTexture(&_selectButtonTexture);
	_selectButton.SetPosition(_selectButtonPos);
	_selectButton.SetStatu(true, false, [&]() { _push = true;  });
	_selectButton.SetSeSound(&_se);

	_checkBoxButton.SetTexture(&_checkBoxTexture);
	_checkBoxButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2 , 600));
	_checkBoxButton.SetStatu(false, true, [&]() {_checkBox = !_checkBox; });
	_checkBox = false;

	_checkButton.SetTexture(&_checkTexture);
	_checkButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 600));

	_closeButton.SetTexture(&_closeButtonTexture);
	_closeButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 870));
	_closeButton.SetStatu(false, true, [&]() {*_openAudioSetting = false; });
	_closeButton.SetSeSound(&_se);

	_push = false;
}

void DollMoveSetting::LoadTexture() 
{
	_barTexture.Load("dollbar.png");
	_baseSelectButtonTexture.Load("��I��.png");
	_selectButtonTexture.Load("�I��.png");
	_checkBoxTexture.Load("�`�F�b�N�{�b�N�X.png");
	_checkTexture.Load("�`�F�b�N.png");
	_closeButtonTexture.Load("�߂�@�e�L�X�g.png");

	_se.Load("BottanClick.mp3");
	
}
void DollMoveSetting::Update()
{
	
	if (_push)
	{
		_selectButtonPos.x = _mousePos.x;
		LimitMove();
		_selectButton.SetPosition(_selectButtonPos);
		CalcuLastPos();
	}
}

void DollMoveSetting::CalcuLastPos()
{
	for (int i = _baseButtonValue; i >= 0; i--)
	{
		if (_selectButtonPos.x >= _barPos.x + _bottonBetweenDistance * i - _baseSelectButtonTexture.GetWidth() / 2 &&
			_selectButtonPos.x <= _barPos.x + _bottonBetweenDistance * i + _baseSelectButtonTexture.GetWidth() / 2)
		{
			_lastSelectButtonPosX = _barPos.x + _bottonBetweenDistance * i;
			return;
		}
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

	/*if (_selectButtonPos.x >= _lastSelectButtonPosX)
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
	else if (_selectButtonPos.x <= _lastSelectButtonPosX)
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
		return _selectButtonPos.x;*/
	return 0;
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
	
	_closeButton.Push();
}

void DollMoveSetting::Pull()
{
	_selectButton.Pull();
	if (_push)
	{
		_push = false;
		_selectButton.SetPosition(Vector2(_lastSelectButtonPosX, _barPos.y + _barTexture.GetHeight() / 2));

	}

	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].Pull();
		
	}

	_checkBoxButton.Pull();
	_checkButton.Pull();

	_closeButton.Pull();
	
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
	_se.Release();

	delete[] _buttonArray;
	
}