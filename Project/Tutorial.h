#pragma once
#include	"ContactFile.h"
#include	"BlockManager.h"
#include	"Block.h"
#include "Trim.h"

class Tutorial
{
private:
	Trim _trimstring;
	ContactFile _contactFile;
	BlockManager* _blockManager;

	bool _end,_start;

	std::pair<int, int>* _tutorialRouteArray;
	int _currentRouteValue,_maxRouteValue;
	int* _inputLimitArray;
	int _inputLimitValue,_currentLimitNumber;

	CTexture* _tutorialTexureArray;
	int _textureValue;

	std::pair<int, int>* _texturePosArray;
	int _texturePosValue;
	int _currentClick;
	bool _hidden;

public:

	void Initialize();
	void ReLoad();
	void SetBlockManager(BlockManager* blockManager) { _blockManager = blockManager; }
	void EndOfPassed(int routeVal);
	void EndMoveDoll();
	void Push();
	void Render();
	void Release();
	
	bool IsEnd() { return _end; }
	bool CheckInTutorialRoute(Block* mouseOnBlock,int routeNumber);
	bool IsHideen()const { return _hidden; }
private:
	void LoadTutorialRoute();
	void LoadInputLimit();
	void LoadTexture();
	void LoadTexturePos();
};
