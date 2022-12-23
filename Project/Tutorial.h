#pragma once
#include	"ContactFile.h"
#include	"BlockManager.h"
#include	"Block.h"
#include "Trim.h"

class Tutorial
{
private:
	bool _end,_start;
	ContactFile _contactFile;
	BlockManager* _blockManager;
	std::pair<int, int>* _tutorialRouteArray;
	int _currentRouteValue,_maxRouteValue;
	int* _inputLimitArray;
	int _inputLimitValue,_currentLimitNumber;

	CTexture* _tutorialTexureArray;
	Trim _trimstring;
	int _textureValue;
public:

	void Initialize();
	void ReLoad();
	void SetBlockManager(BlockManager* blockManager) { _blockManager = blockManager; }
	void EndOfPassed(int routeVal);
	void EndMoveDoll();
	void Render();
	void Release();
	
	bool IsEnd() { return _end; }
	bool CheckInTutorialRoute(Block* mouseOnBlock,int routeNumber);

private:
	void LoadTutorialRoute();
	void LoadInputLimit();
	void LoadTexture();
};
