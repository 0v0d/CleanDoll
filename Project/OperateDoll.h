#pragma once
#include	"vector"
#include	"Doll.h"
#include	"BlockManager.h"
#include	"Block.h"

class OperateDoll
{
	Doll* _doll;
	BlockManager* _blockManager;
	std::vector<Block*> _routeBlockArray;
	int _currentBlockNumber;
public:
	void Initialize();
	void ReLoad();
	void SetDoll(Doll* doll) { _doll = doll; }
	void SetBlockManager(BlockManager* blockManager) { _blockManager = blockManager; }

	void SetRouteBlockArray(std::vector<Block*> blockArray);

	void Release();

private:
	void SetDollNextBlock();
};