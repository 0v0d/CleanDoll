#include "BlockOnObject.h"

void BlockOnObject::Initialzie(){
	if (_accessories->GetType() != ACCESSORIES_TYPE::COIN) _accessories->Initialize();
}

void BlockOnObject::ReLoad() {
	if (_accessories != nullptr) _accessories->ReLoad();
	_hiddenAccessories = false;
}

void BlockOnObject::SetObject(Object* object, bool onSwap){
	_object = object;
	_object->CalcuScale(_blockSize.x * _blockScale);
	_object->SetBlockSize(_blockSize.x, _blockSize.y);
	_object->SetPosition(Vector2(_blockCenterPos.x, _blockCenterPos.y + _blockSize.y / 2 * _blockScale));
	if (onSwap)_object->Swap();
}

void BlockOnObject::SetAccessories(IBaseAccessories* accessories){
	_accessories = accessories;
	_accessories->CalcuScale(_blockSize.x * _blockScale);
	_accessories->SetPosotion(Vector2(_blockCenterPos.x, _blockCenterPos.y + _blockSize.y / 2 * _blockScale));
}

void BlockOnObject::Update(){
	if (_accessories != nullptr) 
	_accessories->Update();
}

void BlockOnObject::Render(){
	if (_object != nullptr) {
		_object->Render();
		return;
	}

	if (_accessories != nullptr) {
		if (!_hiddenAccessories)_accessories->Render();
	}
}

void BlockOnObject::Release(){

}

void BlockOnObject::Delete(){
	DeleteObject();
	DeleteAccessories();
}

void BlockOnObject::DeleteObject() {
	if (_object == nullptr) return;

	_object->Release();
	delete _object;
	_object = nullptr;
}

void BlockOnObject::DeleteAccessories() {
	if (_accessories == nullptr) return;
	if (_accessories->GetType() == ACCESSORIES_TYPE::COIN) return;

	_accessories->Release();
	delete _accessories;
	_accessories = nullptr;
}