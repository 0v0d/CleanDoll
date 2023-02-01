#pragma once
#include	"Block.h"
#include	"Doll.h"
#include	"GalleryCoin.h"
class BlockManager
{
private:
	Block** _blockArray = nullptr;
	int _blockValueX, _blockValueY;
	const float _topSpace = 300;
	const float _bottomSpace = 100;
	float _scale;
	int _dollOnBlockX, _dollOnBlockY;

	const int _adjoinBlockValue = 4;

	Doll* _doll;
	GalleryCoin* _galleryCoin;
public:
	BlockManager();
	~BlockManager();

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
	void HiddenCoin();
private:
	void SetAdjoinBlock();
};