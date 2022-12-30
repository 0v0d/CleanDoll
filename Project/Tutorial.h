#pragma once
#include	"ContactFile.h"
#include	"BlockManager.h"
#include	"Block.h"
#include	"Trim.h"
#include	"EndGameProcess.h"

class Tutorial
{
private:
	Trim _trimstring;
	ContactFile _contactFile;
	BlockManager* _blockManager;

	bool _end;

	std::pair<int, int>* _tutorialRouteArray;
	int _currentRouteValue,_maxRouteValue;
	int* _inputLimitArray;
	int _currentLimitNumber;

	CTexture* _tutorialTexureArray;
	int _textureValue;

	Vector2* _texturePosArray;
	int _currentClick;
	bool _hidden;

	int* _textureHiddenArray;
	int _currentHidden;

	EndGameProcess* _endGameProcess;

public:
	void Initialize();
	void ReLoad();
	void SetBlockManager(BlockManager* blockManager) { _blockManager = blockManager; }
	void SetEndGameProcess(EndGameProcess* endGameProcess) { _endGameProcess = endGameProcess; }

	void EndOfPassed(int routeVal);
	void EndMoveDoll();
	void Push();
	void Render();
	void Release();
	
	bool IsEnd() const { return _end; }
	bool CheckInTutorialRoute(Block* mouseOnBlock,int routeNumber);
	bool IsHideen()const { return _hidden; }
private:
	void LoadTutorialRoute();
	void LoadInputLimit();
	void LoadTexture();
	void LoadTexturePos();
	void LoadTextureHidden();
	int CalcuCurrentLimitValue();
};
