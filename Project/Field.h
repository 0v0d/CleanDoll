#pragma once
#include	"Mof.h"
#include	"vector"
#include	"BlockManager.h"
#include	"EnergyVessels.h"

class Field
{
	BlockManager _blockManager;

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
	int _distanceCount;
	//�O��̓��͂ōŌ�ɉ������u���b�N
	Block* _lastDistanceBlock;

	bool _onMoveDoll;

	//�A�C�e���ŉ񕜂����ړ���
	std::vector<int> _recoveryDifferentialArray;

	int _dustDumpValue, _waterDumpValue;

	EnergyVessels _energyVessels;

public:
	void SetDollPosition(int x,int y);

	void Initialize();
	void ReLoad();
	void Update();
	void PassedMouse(Vector2 mousePosition);
	void EndOfPassed();
	void EndMoveDoll();
	void ReSetStage();

	void SetDustDumpValue(int dumpValue) { _dustDumpValue = dumpValue; }
	void SetWaterDumpValue(int dumpValue) { _waterDumpValue = dumpValue; }
	int* GetDustDumpValue() {return &_dustDumpValue; }
	int* GetWaterDumpValue() { return &_waterDumpValue; }

	void Render();
	void Delete();
	void Release();

	BlockManager* GetBlockManager() { return &_blockManager; }

private:
	void AdvanceRoute(Block* mouseOnBlock);
	void BackRoute(Block* mouseOnBlock);
};