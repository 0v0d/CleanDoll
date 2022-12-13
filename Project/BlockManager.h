#pragma once
#include	"Block.h"
#include	"Doll.h"
#include	"GalleryCoin.h"
class BlockManager
{
private:
	Block** _blockArray = nullptr;
	int _blockValueX, _blockValueY;
	float _topSpace, _bottomSpace;
	float _scale;
	int _dollOnBlockX, _dollOnBlockY;

	const int _adjoinBlockValue = 4;

	Doll* _doll;
	GalleryCoin* _galleryCoin = new GalleryCoin(ACCESSORIES_TYPE::COIN);
public:
	void Initialize();
	void SetDoll(Doll* doll) { _doll = doll; }
	void ReLoad();

	void CalcuBlockPosition();
	void Update();
	void Render();
	void Delete();
	void Release();

	Block* GetBlock(int x, int y) { return &_blockArray[x][y]; }
	Block* GetMouseOnBlock(Vector2 mousePos);
	Block* GetDollOnBlock() { return &_blockArray[_dollOnBlockX][_dollOnBlockY]; }
	int GetAdjoinBlockValue() { return _adjoinBlockValue; }
	float GetScale() { return _scale; }

	void CreateField(int blockValueX, int blockValueY);
	void CalcuScale(float blockSizeY);
	void SetDollOnBlock(Block* dollOnBlock);
	void SetCoin(int x, int y);
private:
	void SetAdjoinBlock();
};