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

	//�ő�ړ���
	const int _maxDistance = 8;
	//�Ȃ���������
	std::vector<Block*> _routeBlockArray;
	//�c��̈ړ���
	int _remainDistance;
	//�����͂��Ă���ړ���
	//int _distanceCount;
	//�O��̓��͂ōŌ�ɉ������u���b�N
	Block* _lastDistanceBlock;

	bool* _onMoveDoll;



	//�A�C�e���ŉ񕜂����ړ���
	std::vector<int> _recoveryDifferentialArray;

	std::pair<int,int>*_tutorialRouteArray;
	int* _inputLimitArray;//txtfile�̗v�f���i�[����

	int _currentNumber;//�v�f�ԍ�
	//_routeBlockArray.size() ���͉�
	int _inputLimitValue;//�e�L�X�g�t�@�C���̈�ԏ�;
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
 