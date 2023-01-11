#include "RemainingDumpUI.h"

void RemainingDumpUI::Initialize() {
	LoadTexture();
	_objectiveSizeX = 100;
	CalcuScale();

	_iconArray[ICON_TYPE::DUST] = new RemainingIcon();
	_iconArray[ICON_TYPE::WATER] = new RemainingIcon();

	IconSetTexture(ICON_TYPE::DUST, &_dustIconTexture);
	IconSetTexture(ICON_TYPE::WATER, &_waterIconTexture);

	_basePosition = Vector2(10,30);
	const float iconSizeX = _dustIconTexture.GetWidth();
	const auto space = Vector2(40,30);
	for (auto itr = _iconArray.begin(); itr != _iconArray.end(); itr++) {
		itr->second->SetScale(_scale);
		itr->second->SetPosition(Vector2(_basePosition.x + space.x * ((int)itr->first * 2 + 1) + iconSizeX * _scale * (int)itr->first, _basePosition.y + _baseTexture.GetHeight() * 2 + space.y));
		float  a = _basePosition.x + space.x * ((int)itr->first * 2 + 1) + iconSizeX * _scale * (int)itr->first;
	}
	constexpr  auto adjustment = 5;
	_remainingDustValue.Initialize();
	_remainingWaterValue.Initialize();
	_remainingDustValue.SetPosition(Vector2(_basePosition.x + (DUST * 2 + 1) + iconSizeX * _scale * DUST + _dustIconTexture.GetWidth() / 4 - adjustment, _basePosition.y + _baseTexture.GetHeight() * 2 + space.y));
	_remainingWaterValue.SetPosition(Vector2(_basePosition.x + (WATER * 2 + 1) + iconSizeX * _scale * WATER + _waterIconTexture.GetWidth() / 2 + adjustment, _basePosition.y + _baseTexture.GetHeight() * 2 + space.y));


}

void RemainingDumpUI::LoadTexture() {
	_baseTexture.Load("base.png");
	_markTexture.Load("checkmark.png");
	_notExistTexture.Load("sonnzaisinai.png");
	_dustIconTexture.Load("icon_hokori.png");
	_waterIconTexture.Load("icon_mizu.png");
	_coinIconTexture.Load("icon_coin.png");
}

void RemainingDumpUI::Update()
{
	_remainingDustValue.SetValue(_dustValue);
	_remainingWaterValue.SetValue(_waterValue);
	_remainingDustValue.CalucRect();
	_remainingWaterValue.CalucRect();
}

void RemainingDumpUI::IconSetTexture(ICON_TYPE iconType, CTexture* iconTexture) {
	_iconArray[iconType]->SetTexture(iconTexture, &_markTexture, &_notExistTexture);
}

void RemainingDumpUI::ReLoad() {
	for (auto itr = _iconArray.begin(); itr != _iconArray.end(); itr++) {
		itr->second->ReLoad();
	}
}

void RemainingDumpUI::CalcuScale() {
	_scale = _objectiveSizeX / _baseTexture.GetWidth();
}


void RemainingDumpUI::SetDustValue(int dumpValue) {
	_dustValue = dumpValue;
	if (_dustValue <= 0) _iconArray[ICON_TYPE::DUST]->SetNotExistFlg(true);
	else _iconArray[ICON_TYPE::DUST]->SetNotExistFlg(false);
}

void RemainingDumpUI::SetWaterValue(int dumpValue) {
	_waterValue = dumpValue;
	if (_waterValue <= 0) _iconArray[ICON_TYPE::WATER]->SetNotExistFlg(true);
	else _iconArray[ICON_TYPE::DUST]->SetNotExistFlg(false);
}

void RemainingDumpUI::CleanDust() {
	_dustValue--;
	_remainingDustValue.SupRemaingValue();

	if (CheckLostDump(_dustValue))MarkIcon(ICON_TYPE::DUST);
}

void RemainingDumpUI::CleanWater() {
	_waterValue--;
	_remainingWaterValue.SupRemaingValue();
	if (CheckLostDump(_waterValue))MarkIcon(ICON_TYPE::WATER);
}

void RemainingDumpUI::MarkIcon(ICON_TYPE iconType) {
	_iconArray[iconType]->MarkIcon();
}
void RemainingDumpUI::GettedCoin() {
	
}
void RemainingDumpUI::Render() {

	_baseTexture.Render(_basePosition.x, _basePosition.y);
	for (auto itr = _iconArray.begin(); itr != _iconArray.end(); itr++) {
		itr->second->Render();
	}
	constexpr auto _space = 10.0f;
	_coinIconTexture.Render(_basePosition.x + _baseTexture.GetWidth() + _space,_basePosition.y);
	_remainingDustValue.Render();
	_remainingWaterValue.Render();
	
}

void RemainingDumpUI::Release() {

	for (auto itr = _iconArray.begin(); itr != _iconArray.end(); itr++) {
		delete itr->second;
	}

	_baseTexture.Release();
	_markTexture.Release();
	_notExistTexture.Release();
	_dustIconTexture.Release();
	_waterIconTexture.Release();
	_coinIconTexture.Release();
	_remainingDustValue.Release();
	_remainingWaterValue.Release();
} 