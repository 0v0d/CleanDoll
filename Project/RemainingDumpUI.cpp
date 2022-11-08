#include "RemainingDumpUI.h"

void RemainingDumpUI::Initialize() {
	LoadTexture();
	_objectiveSizeX = 400;
	CalcuScale();

	_iconArray = new RemainingIcon[_iconValue];
	_iconArray[0].SetTexture(&_dustIconTexture, &_markTexture, &_notExistTexture);
	_iconArray[1].SetTexture(&_waterIconTexture, &_markTexture, &_notExistTexture);
	_iconArray[2].SetTexture(&_coinIconTexture, &_markTexture, &_notExistTexture);

	_basePosition = Vector2(100, 650);
	const float iconSizeX = _dustIconTexture.GetWidth();
	const float space = (_baseTexture.GetWidth() * _scale - iconSizeX * _scale * _iconValue) / (_iconValue * 2);
	for (int i = 0; i < _iconValue; i++) {
		_iconArray[i].SetScale(_scale);
		_iconArray[i].SetPosition(Vector2(_basePosition.x + space * (i * 2 + 1) + iconSizeX * _scale * i, _basePosition.y + _baseTexture.GetHeight() * _scale - space));
	}
}

void RemainingDumpUI::LoadTexture() {
	_baseTexture.Load("base.png");
	_markTexture.Load("checkmark.png");
	_notExistTexture.Load("sonnzaisinai.png");
	_dustIconTexture.Load("icon_hokori.png");
	_waterIconTexture.Load("icon_mizu.png");
	_coinIconTexture.Load("icon_coin.png");
}

void RemainingDumpUI::ReLoad() {
	for (int i = 0; i < _iconValue; i++) {
		_iconArray[i].ReLoad();
	}
}

void RemainingDumpUI::CalcuScale() {
	_scale = _objectiveSizeX / _baseTexture.GetWidth();
}

void RemainingDumpUI::SetDumpValue(int dustValue, int waterValue) {
	_dustValue = dustValue;
	_waterValue = waterValue;
}

void RemainingDumpUI::CleanDust() {
	_dustValue--;
	if (CheckLostDump(_dustValue))MarkIcon(0);
}

void RemainingDumpUI::CleanWater() {
	_waterValue--;
	if (CheckLostDump(_waterValue))MarkIcon(1);
}

void RemainingDumpUI::MarkIcon(int iconNumber) {
	_iconArray[iconNumber].MarkIcon();
}

void RemainingDumpUI::Render() {

	_baseTexture.RenderScale(_basePosition.x, _basePosition.y, _scale);
	for (int i = 0; i < _iconValue; i++) {
		_iconArray[i].Render();
	}
}

void RemainingDumpUI::Release() {
	_baseTexture.Release();
	_markTexture.Release();
	_notExistTexture.Release();
	_dustIconTexture.Release();
	_waterIconTexture.Release();
	_coinIconTexture.Release();
}