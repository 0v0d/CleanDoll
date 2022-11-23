#pragma once
#include	"Mof.h"
#include	"Block.h"
#include	"vector"

class Doll
{
private:
	enum {
		WAIT_1,
		WAIT_2,
		WALK,
		MOTION_COUNT
	};
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
	const int _moveSpeed =40;
	int _moveCount;

	bool _inversion;
	CRectangle _inversionRenderRect;

	int _dustDumpValue,_waterDumpValue;
	CSpriteMotionController	_motionController;
	bool _heldMop;
	const int wait = 3;
	int _motionCount;
	const int _textureValue = 30;
	Vector2 _dollTextureSize;
public:
	void Initialize();
	void SetField(Field* field) { _field = field; }
	void SetPosition(Vector2 blockCenterPosisiton);
	void ReLoad();
	void CalcuScale(float boxSizeY, float scale);
	void SetDumpValue(int dustDumpValue, int waterDumpValue);
	void Update();
	void SetRouteBlockArray(std::vector<Block*> blockArray);
	void Move();
	void Render();
	void Release();
private:
	void DollAnimationInit();
	void DollAnimationUpdate();
	int AnimationRoop();
	void SetNextPosition();
	void ArrivalBlock();
	void ActionAccessories();
	void CleanDump();
	void SwitchToMop();
};