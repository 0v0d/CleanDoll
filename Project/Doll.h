#pragma once
#include	"Mof.h"
#include	"Block.h"
#include	"vector"
class Doll
{
	CTexture _dollTexture;
	Vector2 _dollPosition;
	CRectangle _renderRect;

	float _scale = 0.03;

	class Field* _field;
	std::vector<Block*> _routeBlockArray;

	bool _move;
	int _currentUnderBlockNumber;
	Vector2 _nextPosition;
	//移動速度: 変数分のフレームで目的地に着く
	const int _moveSpeed = 20;
	int _moveCount;

	bool _inversion;
	CRectangle _inversionRenderRect;

	int* _dustDumpValue;
	int* _waterDumpValue;

	bool _heldMop;
	
public:

	void Initialize();
	void SetField(Field* field) { _field = field; }
	void SetPosition(Vector2 blockCenterPosisiton);
	void ReLoad();
	void CalcuScale(float boxSizeY, float scale);
	void SetDumpValue(int* dustDumpValue, int* waterDumpValue);
	void Update();
	void SetRouteBlockArray(std::vector<Block*> blockArray);
	void Move();

	void Render();
	void Release();

private:
	void SetNextPosition();
	void ArrivalBlock();
	void ActionAccessories();
	void CleanDump();
	void SwitchToMop();
};