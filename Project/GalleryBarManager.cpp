#include "GalleryBarManager.h"

void GalleryBarManager::Initialize() {
	LoadTexture();
	_coinNumber.SetPosition();
	_coinNumber.Initialize();
	_requiredCoinValueArray = new int[_barValue] {2, 4, 7, 10};
	_backPos = Vector2(70, 300);
}

void GalleryBarManager::LoadTexture() {
	_barBackGround.Load("stagepreview_base.png");
	_coinNumber.LoadTextrue();
	LoadBarTexture();
	LoadGalleryTexture();
}

void GalleryBarManager::CreateBarArray() {
	_barArray = new GalleryBar[_barValue];
	const float space = 30;
	float posX = _backPos.x + _barBackGround.GetWidth() / 2;
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Initialize();
		_barArray[i].SetBaseScale(CalcuBarScale(space));
		_barArray[i].SetCenterPos(Vector2(posX, CalcuBarCenterPosY(i, space, CalcuBarScale(space))));
	}
	SetTexture();
}

void GalleryBarManager::LoadBarTexture() {
	_contactFile.OpenFile("galleryBar.txt");
	int textureValue = _contactFile.GetValue(true);
	_openedBarTexureArray = new CTexture[_barValue];
	_lockedBarTexureArray = new CTexture[_barValue];
	for (int i = 0; i < _barValue; i++) {
		_lockedBarTexureArray[i].Load(_trimstring.TrimString(_contactFile.GetString(false)).c_str());
		_openedBarTexureArray[i].Load(_trimstring.TrimString(_contactFile.GetString(false)).c_str());
	}
	_contactFile.CloseFile();
}

float GalleryBarManager::CalcuBarScale(float space) {
	return ((_barBackGround.GetHeight() - space*2) / _barValue - space * 2) / _lockedBarTexureArray->GetHeight();
}

float GalleryBarManager::CalcuBarCenterPosY(int number, float space, float scale) {
	return _backPos.y + space + _lockedBarTexureArray->GetHeight() * scale / 2 + (space + _lockedBarTexureArray->GetHeight() * scale) * number;
}

void GalleryBarManager::LoadGalleryTexture() {
	_contactFile.OpenFile("Gallery.txt");

	int barValue = _contactFile.GetValue(true);
	_lockedTexureArray = new CTexture[_barValue];
	_openedTexureArray  = new CTexture[_barValue];
	for (int i = 0;i < barValue;i++) {
		_lockedTexureArray[i].Load(_trimstring.TrimString(_contactFile.GetString(false)).c_str());
		_openedTexureArray[i].Load(_trimstring.TrimString(_contactFile.GetString(false)).c_str());
	}
	_contactFile.CloseFile();
}

void GalleryBarManager::ReLoad() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].ReLoad();
	}
	SetTexture();
}

void GalleryBarManager::SetTexture() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].SetBaseTexture(_gettedCoinValue >= _requiredCoinValueArray[i] ? &_openedBarTexureArray[i] : &_lockedBarTexureArray[i]);
	}
}

void GalleryBarManager::Update() {
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

CTexture* GalleryBarManager::GetPickTexture() {
	for (int i = 0;i < _barValue;i++) {
		if (_barArray[i].IsPickUp()) {
			return _gettedCoinValue >= _requiredCoinValueArray[i] ? &_openedTexureArray[i] : &_lockedTexureArray[i];
		}
	}
	return nullptr;
}


void GalleryBarManager::Render() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Render();
	}
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
	
	_barBackGround.Release();
	_coinNumber.Release();
}