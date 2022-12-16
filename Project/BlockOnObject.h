#pragma once
#include	"mof.h"
#include	"Object.h"
#include	"IBaseAccessories.h"
class BlockOnObject
{
	Object* _object = nullptr;
	IBaseAccessories* _accessories = nullptr;

	bool _hiddenAccessories = false;

	Vector2 _blockCenterPos;
	Vector2 _blockSize;
	float _blockScale;
	
public:
	void Initialzie();
	void SetBlockCenterPosition(Vector2 pos) { _blockCenterPos = pos; }
	void SetBlockSize(Vector2 size) { _blockSize = size; }
	void SetBlockScale(float scale) { _blockScale = scale; }
	void ReLoad();

	void SetObject(Object* object, bool onSwap);
	void SetAccessories(IBaseAccessories*);

	void Update();
	void HiddenAccessoriesFlg(bool flg) { _hiddenAccessories = flg; }

	void Render();
	void Release();
	void Delete();

	IBaseAccessories* GetAccessories() { return _accessories; }
	ACCESSORIES_TYPE GetAccessoriesTypr() { return _accessories->GetType(); }
	Object* GetFurniture() { return _object; }

private:

	void DeleteObject();
	void DeleteAccessories();
};
