#include "BlockOnObject.h"

void BlockOnObject::Initialzie(){
	_hiddenAccessories = false;
	_accessories->Initialize();
}

void BlockOnObject::ReLoad() {
	if (_accessories != nullptr)
	_accessories->ReLoad();
}

void BlockOnObject::SetObject(Object* object, bool onSwap){
	_object = object;
	_object->CalcuScale(_blockSize.x * _blockScale);
	_object->SetBlockSize(_blockSize.x, _blockSize.y);
	_object->SetPosition(Vector2(_blockCenterPos.x, _blockCenterPos.y + _blockSize.y / 2 * _blockScale));
	if (onSwap)_object->Swap();
}

void BlockOnObject::SetAccessories(IBaseAccessories* accessories, ACCESSORIES_TYPE type){
	_accessories = accessories;
	_accessories->CalcuScale(_blockSize.x * _blockScale);
	_accessories->SetPosotion(_blockCenterPos);
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
		_accessories->Render();
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

	_accessories->Release();
	delete _accessories;
	_accessories = nullptr;
}