#include "RemainingDumpUI.h"

void RemainingDumpUI::Initialize() {
	LoadTexture();
	_objectiveSizeX = 400;
	CalcuScale();

	_iconArray[ICON_TYPE::DUST] = new RemainingIcon();
	_iconArray[ICON_TYPE::WATER] = new RemainingIcon();
	_iconArray[ICON_TYPE::COIN] = new RemainingIcon();

	IconSetTexture(ICON_TYPE::DUST, &_dustIconTexture);
	IconSetTexture(ICON_TYPE::WATER, &_waterIconTexture);
	IconSetTexture(ICON_TYPE::COIN, &_coinIconTexture);

	_basePosition = Vector2(g_pGraphics->GetTargetWidth() - _baseTexture.GetWidth() * _scale - 100, g_pGraphics->GetTargetHeight() - _baseTexture.GetHeight() * _scale -50);
	const float iconSizeX = _dustIconTexture.GetWidth();
	const float space = (_baseTexture.GetWidth() * _scale - iconSizeX * _scale * _iconArray.size()) / (_iconArray.size() * 2);
	for (auto itr = _iconArray.begin(); itr != _iconArray.end(); itr++) {
		itr->second->SetScale(_scale);
		itr->second->SetPosition(Vector2(_basePosition.x + space * ((int)itr->first * 2 + 1) + iconSizeX * _scale * (int)itr->first, _basePosition.y + _baseTexture.GetHeight() * _scale - space));
	}
	_remainingValue.Initialize();
	_remainingValue.SetOnValueCircleScale(_scale);
	_remainingValue.SetPosition(_basePosition);
	
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
	_remainingValue.SetMaxRemaingingValue(_dustValue+_waterValue);
	_remainingValue.CalucRect();
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
	_remainingValue.SupRemaingValue();
	if (CheckLostDump(_dustValue))MarkIcon(ICON_TYPE::DUST);
}

void RemainingDumpUI::CleanWater() {
	_waterValue--;
	_remainingValue.SupRemaingValue();
	if (CheckLostDump(_waterValue))MarkIcon(ICON_TYPE::WATER);
}

void RemainingDumpUI::MarkIcon(ICON_TYPE iconType) {
	_iconArray[iconType]->MarkIcon();
}

void RemainingDumpUI::Render() {

	_baseTexture.RenderScale(_basePosition.x, _basePosition.y, _scale);
	for (auto itr = _iconArray.begin(); itr != _iconArray.end(); itr++) {
		itr->second->Render();
	}
	_remainingValue.Render();
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
	_remainingValue.Release();
}