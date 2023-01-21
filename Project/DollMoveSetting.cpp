#include "DollMoveSetting.h"
#include "SceneManager.h"
#include "GameScene.h"

void DollMoveSetting::Initialize()
{
	_baseSpaseCount = _baseButtonValue - 1;
	_factorTextureArray = new CTexture[_baseButtonValue];

	LoadTexture();
	LoadSound();
	_barPos = Vector2(g_pGraphics->GetTargetWidth() / 2 - _barTexture.GetWidth() / 2, 350);
	_bottonBetweenDistance = _barTexture.GetWidth() / _baseSpaseCount;
	
	//‰½”Ô–Ú‚©
	int initButtonNumber = 1;
	_selectButtonPos = Vector2(_barPos.x + _bottonBetweenDistance * initButtonNumber, _barPos.y + _barTexture.GetHeight() / 2);
	_lastSelectButtonPosX = _barPos.x + _bottonBetweenDistance * initButtonNumber;
	
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].SetTexture(&_baseSelectButtonTexture);
		_buttonArray[i].SetPosition(Vector2(_barPos.x + _bottonBetweenDistance * i, _barPos.y+ _barTexture.GetHeight()/2));
		_buttonArray[i].SetSeSound(&_se);
	}

	SetMethodButton();

	_selectButton.SetTexture(&_selectButtonTexture);
	_selectButton.SetPosition(_selectButtonPos);
	_selectButton.SetStatu(true, false, [&]() { _push = true;  });
	_selectButton.SetSeSound(&_se);

	_closeButton.SetTexture(&_closeButtonTexture);
	_closeButton.SetPosition(Vector2(g_pGraphics->GetTargetWidth() / 2, 870));
	_closeButton.SetStatu(false, true, [&]() {*_openAudioSetting = false; });
	_closeButton.SetSeSound(&_se);

	_push = false;

	_factorArray = new float[_baseButtonValue] {0.5f, 1, 1.5f, 2, 4};
	dynamic_cast<GameScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::GAME))->GetField()->SetDollSpeedFactor(_factorArray[initButtonNumber]);
}

void DollMoveSetting::LoadTexture() 
{
	_barTexture.Load("dollbar.png");
	_baseSelectButtonTexture.Load("”ñ‘I‘ð.png");
	_selectButtonTexture.Load("‘I‘ð.png");
	_closeButtonTexture.Load("–ß‚é@ƒeƒLƒXƒg.png");

	_factorTextureArray[0].Load("~0.5.png");
	_factorTextureArray[1].Load("~1.png");
	_factorTextureArray[2].Load("~1.5.png");
	_factorTextureArray[3].Load("~2.png");
	_factorTextureArray[4].Load("~4.png");

	_logoTexture.Load("ƒh[ƒ‹‘¬“xÝ’è.png");
}

void DollMoveSetting::LoadSound() {
	_se.Load("BottanClick.mp3");
}

void DollMoveSetting::SetMethodButton() {
	_buttonArray[0].SetStatu(false, true, [&]() {
		_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 0;
		_selectButton.SetPosition(_selectButtonPos);
		CalcuLastPos();
		});
	_buttonArray[1].SetStatu(false, true, [&]() {
		_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 1;
		_selectButton.SetPosition(_selectButtonPos);
		CalcuLastPos();
		});
	_buttonArray[2].SetStatu(false, true, [&]() {
		_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 2;
		_selectButton.SetPosition(_selectButtonPos);
		CalcuLastPos();
		});
	_buttonArray[3].SetStatu(false, true, [&]() {
		_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 3;
		_selectButton.SetPosition(_selectButtonPos);
		CalcuLastPos();
		});
	_buttonArray[4].SetStatu(false, true, [&]() {
		_selectButtonPos.x = _barPos.x + _bottonBetweenDistance * 4;
		_selectButton.SetPosition(_selectButtonPos);
		CalcuLastPos();
		});
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

			dynamic_cast<GameScene*>(SceneManager::Instance().GetScene(SCENE_TYPE::GAME))->GetField()->SetDollSpeedFactor(_factorArray[i]);
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

void DollMoveSetting::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].SetMousePos(mousePos);
	}
	_selectButton.SetMousePos(mousePos);
	_closeButton.SetMousePos(mousePos);
}

void DollMoveSetting::Push()
{
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].Push();
	}

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

	_closeButton.Pull();
}

void DollMoveSetting::Render()
{
	_barTexture.Render(_barPos.x,_barPos.y);
	for (int i = 0; i < _baseButtonValue; i++)
	{
		_buttonArray[i].Render();
		const float iconScale = 0.2f;
		_factorTextureArray[i].RenderScale(_barPos.x + _bottonBetweenDistance * i - _factorTextureArray[i].GetWidth()/2*iconScale, _barPos.y + _barTexture.GetHeight() + 50, iconScale);
	}
	_closeButton.Render();
	_selectButton.Render();

	_logoTexture.Render(g_pGraphics->GetTargetWidth() / 2 - _logoTexture.GetWidth() / 2, 100);
}

void DollMoveSetting::Release()
{
	_baseSelectButtonTexture.Release();
	_selectButtonTexture.Release();
	_barTexture.Release();
	_closeButtonTexture.Release();
	_se.Release();
	_logoTexture.Release();

	for (int i = 0;i < _baseButtonValue;i++) {
		_factorTextureArray->Release();
	}

	delete[] _buttonArray;
	delete[] _factorArray;
	delete[] _factorTextureArray;
}