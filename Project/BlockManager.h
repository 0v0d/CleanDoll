#pragma once
#include	"Block.h"
#include	"Doll.h"
class BlockManager
{
private:
	Block** _blockArray;
	int _blockValueX, _blockValueY;
	float _topSpace, _bottomSpace;
	float _scale;
	int _dollOnBlockX, _dollOnBlockY;

	const int _adjoinBlockValue = 4;

	Doll* _doll;
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
	int GetAdjoinBlockValue() { return _adjoinBlockValue; }
	float GetScale() { return _scale; }

	void CreateField(int blockValueX, int blockValueY);
	void CalcuScale(float blockSizeY);
	void SetDollOnBlock(Block* dollOnBlock);
private:
	void SetAdjoinBlock();
};