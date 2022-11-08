#pragma once
#include	"Block.h"
class BlockManager
{
private:
	Block** _blockArray;
	int _blockValueX, _blockValueY;
	float _topSpace, _bottomSpace;
	float _scale;

	const int _adjoinBlockValue = 4;
public:
	void Initialize();
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
private:
	void SetAdjoinBlock();
};