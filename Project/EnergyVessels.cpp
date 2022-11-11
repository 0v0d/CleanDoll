#include "EnergyVessels.h"

void EnergyVessels::Initialize()
{
	LoadTexture();

	_vesselsPosition = Vector2(g_pGraphics->GetTargetWidth() - _energyVesselsTexture.GetWidth() * _scale - 50, 500);
	_remainPosition = Vector2
	(_vesselsPosition.x + _energyVesselsTexture.GetWidth() * _scale / 2 - _remainEnergyTexture.GetWidth() * _scale / 2,
		_vesselsPosition.y - _remainEnergyTexture.GetHeight() * _scale + _remainEnergyTexture.GetHeight() * _scale * 0.5f);

	_renderColorArray = 
	{
		{5,MOF_COLOR_GREEN},
		{3,MOF_COLOR_YELLOW},
		{0,MOF_COLOR_RED},
	};

	_dollOnEnergyVessels.SetFacialExpressionValue(_variationValue);
	_dollOnEnergyVessels.SetScale(_scale);
	_dollOnEnergyVessels.SetPosition(Vector2(_vesselsPosition.x + _energyVesselsTexture.GetWidth() * _scale / 2,
		_vesselsPosition.y + _energyVesselsTexture.GetHeight() * _scale / 2));
}

void EnergyVessels::ReLoad()
{

	for (int i = 0; i < _maxEnergyValue; i++)
	{
		_energyBarArray[i].ChangeColor(&_renderColorArray[5]);
	}
	_dollOnEnergyVessels.ChangeFaceEzpression(_variationValue);
}


void EnergyVessels::LoadTexture()
{
	_energyVesselsTexture.Load("EnergyVessels.png");
	_energyBarTexture.Load("EnergyBar.png");
	_remainEnergyTexture.Load("残りエネルギー.png");
	_dollOnEnergyVessels.LoadTexture();
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
		_energyBarArray[i].SetScale(_scale);
		_energyBarArray[i].SetBasePosition(Vector2(_vesselsPosition.x + _energyVesselsTexture.GetWidth() * _scale / 2,
			_vesselsPosition.y + _energyVesselsTexture.GetHeight() * _scale / 2));
		_energyBarArray[i].Initialize();
	}
}

void EnergyVessels::Update()
{

}

void EnergyVessels::CheckChangeEnergyColor()
{
	int energyColorCount = 0;

	for (auto itr = _renderColorArray.begin();itr != _renderColorArray.end();itr++) 
	{
		if (*_currentEnergyValue >= itr->first) 
		{
			for (int i = 0;i < *_currentEnergyValue;i++)
			{
				_energyBarArray[i].ChangeColor(&itr->second);
			}
			energyColorCount++;
		}
	}

	_dollOnEnergyVessels.ChangeFaceEzpression(_variationValue - energyColorCount);
}

void EnergyVessels::Render()
{	
	for (int i = 0;i < _maxEnergyValue;i++) 
	{
		*_currentEnergyValue > i ? _energyBarArray[i].Render() : _energyBarArray[i].UsedEnergyRender();
	}

	_energyVesselsTexture.RenderScale(_vesselsPosition.x, _vesselsPosition.y, _scale);
	_remainEnergyTexture.RenderScale(_remainPosition.x, _remainPosition.y, _scale);
	_dollOnEnergyVessels.Render();
}

void EnergyVessels::Release()
{
	delete[] _energyBarArray;
	
	_energyVesselsTexture.Release();
	_energyBarTexture.Release();
	_remainEnergyTexture.Release();
	_dollOnEnergyVessels.Release();
}