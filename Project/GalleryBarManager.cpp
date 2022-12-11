#include "GalleryBarManager.h"

void GalleryBarManager::Initialize() {
	LoadTexture();

	_requiredCoinValueArray = new int[_barValue] {2, 5, 8, 11, 15};
}

void GalleryBarManager::LoadTexture() {
	_barBackGround.Load("stagepreview_base.png");
	_barTexture.Load("BaseCleanBar.png");
	_lockTexture.Load("BaseDirtyBar.png");
}

void GalleryBarManager::CreateBarArray() {
	_barArray = new GalleryBar[_barValue];

	const float space = 30;
	const float scale= CalcuBarScale(space);
	float posX = _backPos.x + _barBackGround.GetWidth() / 2;
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Initialize();
		_barArray[i].SetBaseScale(scale);
		_barArray[i].SetCenterPos(Vector2(posX, CalcuBarCenterPosY(i, space, scale)));
	}

	SetTexture();
	SetBarData();
}

float GalleryBarManager::CalcuBarScale(float space) {
	return ((_barBackGround.GetHeight() - space) / _barValue - space) / _barTexture.GetHeight();
}

float GalleryBarManager::CalcuBarCenterPosY(int number, float space, float scale) {
	return _backPos.y + space + _barTexture.GetHeight() * scale / 2 + (space + _barTexture.GetHeight() * scale) * number;
}

void GalleryBarManager::SetBarData() {
	_contactFile.OpenFile("Gallery.txt");

	int a = _contactFile.GetValue(true);
	for (int i = 0;i < a;i++) {
		_barArray[i].SetLockedTextTexture(_contactFile.GetString(false));
		_barArray[i].SetGalleryTexture(_contactFile.GetString(false));
	}

	_contactFile.CloseFile();
}

void GalleryBarManager::SetBasePos(Vector2 centerPos) {
	_backPos = Vector2(centerPos.x, g_pGraphics->GetTargetHeight() / 2 - _barBackGround.GetHeight() / 2);
}


void GalleryBarManager::ReLoad() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].ReLoad();
	}
	SetTexture();
}

void GalleryBarManager::SetTexture() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].SetBaseTexture(_gettedCoinValue >= _requiredCoinValueArray[i] ? &_barTexture : &_lockTexture);
	}
}

void GalleryBarManager::Update() {
	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) {
		AddCoinValue();
		ReLoad();
	}
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
			return _barArray[i].GetGaleryTexture();
		}
	}
	return nullptr;
}


void GalleryBarManager::Render() {
	
	_barBackGround.Render(_backPos.x, _backPos.y);
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Render();
	}
}

void GalleryBarManager::Release() {
	for (int i = 0;i < _barValue;i++) {
		_barArray[i].Release();
	}
	delete[] _barArray;
	delete[] _requiredCoinValueArray;

	_barBackGround.Release();
	_barTexture.Release();
	_lockTexture.Release();
}