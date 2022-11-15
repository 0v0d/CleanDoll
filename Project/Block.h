#pragma once
#include	"Mof.h"
#include	"Object.h"
#include	"IBaseAccessories.h"
#include	"Wall.h"

class Block
{
private:
	CTexture* _blockTexture = nullptr;
	Vector2 _position;
	const float _hitBoxScale = 0.2f;
	float _blockSizeX, _blockSizeY;
	float _scale;

	//周りのブロック　0:左, 1:上, 2:右, 3:下
	Block** _adjoinBlockArray;

	Object* _object = nullptr;
	IBaseAccessories* _accessories = nullptr;

	//0:左, 1:右, 2:中
	Wall* _wallArray = nullptr;
	const int _wallValue = 3;

	bool _passed;

	MofU32 _passedBlockColor = MOF_COLOR_RED;

	bool _hiddenAccessories;

public:
	void SetTexture(CTexture* blockTexture);
	void SetPosition(int x, int y, float topSpace);
	void SetScale(float scale) { _scale = scale; }
	void SetAdjoinBlockValue(int adjoinBlockValue);
	void SetAdjoinBlock(Block* block, int number);
	Block** GetAdjoinBlockArray() { return _adjoinBlockArray; }

	void SetObject(Object* object,bool onSwap);
	void SetAccessories(IBaseAccessories* accessories);
	void CreateWall();
	void SetWall(CTexture* wallTexture, int number);
	void SetWallObject(CTexture* wallTexture, int number);

	void Initialize();
	void ReLoad();
	void Update();

	void SetPassedFlg(bool flg) { _passed = flg; }
	bool IsPassed() { return _passed; }
	void HiddenAccessoriesFlg(bool flg) { _hiddenAccessories = flg; }
	bool IsHeldObject() { return _object != nullptr; }

	void Render();
	void RenderBlcokOnObject();
	void Release();

	void Delete();
	void DeleteObject();
	void DeleteAccessories();

	Vector2 GetBlockSize() { return Vector2(_blockSizeX,_blockSizeY); }

	IBaseAccessories* GetAccessories() { return _accessories; }
	Vector2 GetCenterPosition() { return Vector2(_position.x + _blockTexture->GetWidth() * _scale /2, _position.y + _blockTexture->GetHeight() * _scale /2); }
	bool CheckMouseOnBlock(Vector2 mousePos);
};