#include "GalleryBarManager.h"

void GalleryBarManager::Initialize() {
	LoadTexture();
	CreateBarArray();

	_requiredCoinValueArray = new int[_barValue]{2,4,7,10 };
	constexpr float maxCoinNumberSpace = 70;
	_maxCoinValue.SetStats(&_numberTexture, _numberScale, _numberValue);
	_maxCoinValue.SetPosition(Vector2(g_pGraphics->GetTargetWidth() - _numberTexture.GetWidth() * _numberScale / _numberValue - maxCoinNumberSpace, 50));
	_maxCoinValue.SetValue(_numberValue - 1);

	constexpr float coinNumberSpace = 200;
	_coinNumber.SetStats(&_numberTexture, _numberScale, _numberValue);
	_coinNumber.SetPosition(Vector2(g_pGraphics->GetTargetWidth() -_numberTexture.GetWidth()*_numberScale/_numberValue - coinNumberSpace,50));

	for (int i = 0;i < _barValue;i++) {
		_barArray[i].SetBaseTexture(&_barTexture);
		_barArray[i].CalcuRect(i, _barValue, true);
		_barArray[i].CalcuPos();
	}
}

void GalleryBarManager::LoadTexture() {
	_barTexture.Load("gallerybar.png");
	_numberTexture.Load("coinnum.png");

	LoadGalleryTexture();
}

void GalleryBarManager::CreateBarArray() {
	_barArray = new GalleryBar[_barValue];
	const float space = 30;
	float posX = _backPos.x + _barBackSize.x / 2 + space;
	float scale = CalcuBarScale(space);
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Initialize();
		_barArray[i].SetBaseScale(scale);
		_barArray[i].SetCenterPos(Vector2(posX, CalcuBarCenterPosY(i, space, scale)));
	}
}

void GalleryBarManager::LoadGalleryTexture() {
	_contactFile.OpenFile("Gallery.txt");

	int barValue = _contactFile.GetValue(true);
	_lockedTexureArray = new CTexture[_barValue];
	_openedTexureArray = new CTexture[_barValue];
	for (int i = 0; i < _barValue; i++) {
		_lockedTexureArray[i].Load(_trimstring.TrimString(_contactFile.GetString(false)).c_str());
		_openedTexureArray[i].Load(_trimstring.TrimString(_contactFile.GetString(false)).c_str());
	}
	_contactFile.CloseFile();
}

float GalleryBarManager::CalcuBarScale(float space) {
	return ((_barBackSize.y - space * 2 * _barValue)-space) / _barValue / _barTexture.GetHeight();
}

float GalleryBarManager::CalcuBarCenterPosY(int number, float space, float scale) {
	return _backPos.y + space + _barTexture.GetHeight() * scale / 2 + (space + _barTexture.GetHeight() * scale) * number;
}

void GalleryBarManager::ReLoad() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].ReLoad();
		_barArray[i].CalcuRect(i, _barValue, _gotCoinValue >= _requiredCoinValueArray[i]);
	}
}

void GalleryBarManager::Update() {
}

void GalleryBarManager::AddCoinValue() {
	_gotCoinValue++;
	_coinNumber.SetValue(_gotCoinValue);
}

void GalleryBarManager::SetMousePos(Vector2 mousePos) {
	_mousePos = mousePos;
}

void GalleryBarManager::Push() {
	PickUpBar();
}

void GalleryBarManager::PickUpBar() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].PickUpFlg(false);
		if (_barArray[i].CheckOnMouse(_mousePos)) {
			_barArray[i].PickUpFlg(true);
		}
	}
}

void GalleryBarManager::Pull() {

}

CTexture* GalleryBarManager::GetMouseOnBarTexture() {

	for (int i = 0; i < _barValue; i++) {
		if (!_barArray[i].CheckOnMouse(_mousePos)) continue;
		_lockedPopUpTexture = _gotCoinValue < _requiredCoinValueArray[i];
		return _lockedPopUpTexture ? &_lockedTexureArray[i] : &_openedTexureArray[i];
	}
	return nullptr;
}

CTexture* GalleryBarManager::GetGalleryTexture(int number) {

	if (0 > number || number >= _barValue) number = 0;
	_lockedPopUpTexture = _gotCoinValue < _requiredCoinValueArray[number];
	return   _lockedPopUpTexture ? &_lockedTexureArray[number] : &_openedTexureArray[number];
}


void GalleryBarManager::Render() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Render();
	}
	_maxCoinValue.Render();
	_coinNumber.Render();
}

void GalleryBarManager::Release() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Release();
	}
	delete[] _barArray;
	delete[] _requiredCoinValueArray;
	delete[] _openedBarTexureArray;
	delete[] _lockedBarTexureArray;
	delete[] _openedTexureArray;
	delete[] _lockedTexureArray;
	_numberTexture.Release();
	_barTexture.Release();
}
