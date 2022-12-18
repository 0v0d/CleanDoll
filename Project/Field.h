#pragma once
#include	"Mof.h"
#include	"vector"
#include	"BlockManager.h"
#include	"FieldUI.h"
#include	"EndGameProcess.h"
#include	"Doll.h"
#include	"OperateDoll.h"

class Field
{
private:
	BlockManager _blockManager;
	OperateDoll _operateDoll;
	Doll _doll;

	Vector2 _mousePos;
	int _blockValueX, _blockValueY;
	int _dollInitialPositionX, _dollInitialPositionY;
	int _adjoinBlockValue;
	Block* _pickedBlock;

	//最大移動回数
	const int _maxDistance = 8;
	//なぞった道順
	std::vector<Block*> _routeBlockArray;
	//残りの移動回数
	int _remainDistance;
	//今入力している移動回数
	//int _distanceCount;
	//前回の入力で最後に押したブロック
	Block* _lastDistanceBlock;

	bool* _onMoveDoll;



	//アイテムで回復した移動回数
	std::vector<int> _recoveryDifferentialArray;

	std::pair<int,int>*_tutorialRouteArray;
	int* _inputLimitArray;//txtfileの要素を格納する

	int _currentNumber;//要素番号
	//_routeBlockArray.size() 入力回数
	int _inputLimitValue;//テキストファイルの一番上;
	int _dustDumpValue, _waterDumpValue;
	int  _initalDustValue, _initalWaterValue;

	bool _push;
	bool _tutorialClear;
	int _routeSize;
	int _tutorialArrayMaxValue;
	

	FieldUI _fieldUI;
	EndGameProcess _endGameProcess;
public:
	void SetDollPosition(int x, int y);
	void Initialize();
	void ReLoad();

	void Update();
	void SetMousePos(Vector2 mousePos);
	void Push();
	void Pull();

	void PassedMouse(Vector2 mousePosition);
	void EndOfPassed();
	void EndMoveDoll();
	void ReSetStage();

	void SetDustDumpValue(int dumpValue);
	void SetWaterDumpValue(int dumpValue);
	void CleanDust();
	void CleanWater();
	void GameOver();

	void Render();
	void Release();

	BlockManager* GetBlockManager() { return &_blockManager; }

	void SetDollMove(bool* onMoveDoll) { _onMoveDoll = onMoveDoll; }
	void SetDollOnBlockNumber( Block* dollOnBlock);
	void SetTutorialRouteArray(std::pair<int, int>** tutorialRouteArray) { _tutorialRouteArray = *tutorialRouteArray; }
	void SetTutorialRoute(int x, int y)
	{
		_tutorialRouteArray[_routeSize].first = x;
		_tutorialRouteArray[_routeSize].second =y;
		_routeSize++;
	}
	void SetTutorialArrayMaxValue(int maxValue) { _tutorialArrayMaxValue = maxValue; }
	void SetInputLimitValue(int inputLimitValue) { _inputLimitValue = inputLimitValue; }
	void SetInputLimitArray(int* inputLimitArray) { _inputLimitArray = inputLimitArray; }
private:

	void AdvanceRoute(Block* mouseOnBlock);
	void BackRoute(Block* mouseOnBlock);
};
 