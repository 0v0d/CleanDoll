#pragma once
#include	"Mof.h"
#include	"vector"
#include	"BlockManager.h"
#include	"FieldUI.h"
#include	"EndGameProcess.h"
#include	"Doll.h"
#include	"OperateDoll.h"
#include	"Tutorial.h"

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

	int _dustDumpValue, _waterDumpValue;
	int  _initalDustValue, _initalWaterValue;

	bool _push;

	Tutorial _tutorial;

	FieldUI _fieldUI;
	EndGameProcess _endGameProcess;
	bool _getCoin;

	Button _clearButton;
	CTexture _clearButtonTexture;
	CSoundBuffer _buttonSe;
	bool _show;

	bool _pushReset;

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
	void SetGettedCoinFlg(bool flg) {_getCoin = flg; }
	void GetCoin();
	void GameOver();
	void SetDollSpeedFactor(float factor) { _doll.CalcuSpeed(factor); }

	void Render();
	void Release();

	BlockManager* GetBlockManager() { return &_blockManager; }

	void SetDollMove(bool* onMoveDoll) { _onMoveDoll = onMoveDoll; }
	void SetDollOnBlockNumber(Block* dollOnBlock);

private:
	void AdvanceRoute(Block* mouseOnBlock);
	void BackRoute(Block* mouseOnBlock);
	bool CheckCantMoveDoll();
	void GameClear();
	void CreateButton();
	void LoadTexture();
};