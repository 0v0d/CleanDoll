#include "EnergyVessels.h"

void EnergyVessels::Initialize()
{
	LoadTexture();
	CalucScale();
	CalucPosition();

	_renderColorArray = 
	{
		{5,MOF_COLOR_GREEN},
		{3,MOF_COLOR_YELLOW},
		{0,MOF_COLOR_RED},
	};

	_energyValue.SetScale(_energyVesselsScale);
	_energyValue.Initialize();
	_energyValue.SetPosition(Vector2(_vesselsPosition.x + _energyVesselsTexture.GetWidth() * _energyVesselsScale/ 2,
		_vesselsPosition.y + _energyVesselsTexture.GetHeight() * _energyVesselsScale/ 2));

	//呼び出し順がおかしい
	if (_energyBarArray != nullptr) SetBarStatu();

	_slideInVessels.SetStatu(_vesselsPosition.x, &_vesselsPosition.x, true);
	_slideInVesselsCenter.SetStatu(_energyVesselsCenterPosition.x, &_energyVesselsCenterPosition.x,  true);
	_slideInRemainEnergy.SetStatu(_remainPosition.x, &_remainPosition.x, true);
}


void EnergyVessels::CalucPosition()
{
	_vesselsPosition = Vector2( 50,
		g_pGraphics->GetTargetHeight() - _energyVesselsTexture.GetHeight() * _energyVesselsScale - 50);

	_remainPosition = Vector2
	(_vesselsPosition.x + _energyVesselsTexture.GetWidth() * _energyVesselsScale / 2 - _remainEnergyTexture.GetWidth() * _remainEnergyScale * 0.5f,
		_vesselsPosition.y - _remainEnergyTexture.GetHeight() * _energyVesselsScale - _remainEnergyTexture.GetHeight() * _remainEnergyScale / 4);

	_energyVesselsCenterPosition = Vector2(_vesselsPosition.x + _energyVesselsTexture.GetWidth() * _energyVesselsScale / 2 - _energyVesselsCenterTexture.GetWidth()* _energyVesselsScale / 2,
		_vesselsPosition.y - _energyVesselsTexture.GetHeight() * _energyVesselsScale / 2 + _energyVesselsCenterTexture.GetHeight()*_energyVesselsScale);
}

void EnergyVessels::ReLoad()
{
	for (int i = 0; i < _maxEnergyValue; i++){
		_energyBarArray[i].ChangeColor(&_renderColorArray[5]);
	}
	ChangeEnergyColor();
	_slideInVessels.Start();
	_slideInVesselsCenter.Start();
	_slideInRemainEnergy.Start();
	_energyValue.ReLoad();
}

void EnergyVessels::LoadTexture()
{
	_energyVesselsTexture.Load("EnergyVessels.png");
	_energyBarTexture.Load("EnergyBar.png");
	_remainEnergyTexture.Load("残りエネルギー.png");
	_energyVesselsCenterTexture.Load("EnergyVesselsCenter.png");
}

void EnergyVessels::SetMaxEnergyValue(int energyValue)
{
	_maxEnergyValue = energyValue;
	CreateEnergyBarArray();
	SetBarStatu();
}

void EnergyVessels::CreateEnergyBarArray()
{
	_energyBarArray = new EnergyBar[_maxEnergyValue];
}

void EnergyVessels::SetBarStatu()
{
	for (int i = 0;i < _maxEnergyValue;i++)
	{
		_energyBarArray[i].SetTexture(&_energyBarTexture);
		_energyBarArray[i].SetBarValue(_maxEnergyValue);
		_energyBarArray[i].SetNumber(i);
		_energyBarArray[i].SetScale(_energyVesselsScale);
		_energyBarArray[i].SetBasePosition(Vector2(_vesselsPosition.x + _energyVesselsTexture.GetWidth() * _energyVesselsScale/ 2,
			_vesselsPosition.y + _energyVesselsTexture.GetHeight() * _energyVesselsScale/ 2));
		_energyBarArray[i].Initialize();
	}
}

void EnergyVessels::Update()
{
	
	_slideInVessels.Update();
	_slideInVesselsCenter.Update();
	_slideInRemainEnergy.Update();
	_energyValue.Update();
}

void EnergyVessels::SetCurrentEnergyValue(int currentEnergyValue) {
	_currentEnergyValue = currentEnergyValue; 
	ChangeEnergyColor();
}

void EnergyVessels::ChangeEnergyColor()
{
	int energyColorCount = 0;

	for (auto itr = _renderColorArray.begin();itr != _renderColorArray.end();itr++) {
		if (_currentEnergyValue >= itr->first) {
			for (int i = 0;i < _currentEnergyValue;i++){
				_energyBarArray[i].ChangeColor(&itr->second);
			}
			energyColorCount++;
		}
	}
}

void EnergyVessels::CalucScale()
{
	_remainEnergyScale =  static_cast<float>(_remainEnergyTexture.GetWidth()) / static_cast<float>(_energyVesselsTexture.GetWidth());
}

void EnergyVessels::Render()
{	
	_energyVesselsCenterTexture.RenderScale(_energyVesselsCenterPosition.x, _energyVesselsCenterPosition.y, _energyVesselsScale);
	_energyVesselsTexture.RenderScale(_vesselsPosition.x, _vesselsPosition.y, _energyVesselsScale);
	_remainEnergyTexture.RenderScale(_remainPosition.x, _remainPosition.y, _remainEnergyScale);

	_energyValue.CalcuRect(_currentEnergyValue);
	for (int i = 0; i < _maxEnergyValue; i++)
	{
		if (_currentEnergyValue > i) {
			_energyBarArray[i].Render();
		};
	}
	_energyValue.Render();
}

void EnergyVessels::Release()
{
	delete[] _energyBarArray;

	_energyVesselsTexture.Release();
	_energyBarTexture.Release();
	_remainEnergyTexture.Release();
	_energyValue.Release();
	_energyVesselsCenterTexture.Release();
}