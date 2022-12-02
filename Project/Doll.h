#pragma once
#include	"Mof.h"
#include	"Block.h"
#include	"DollAnimation.h"
#include	"vector"
#include	"functional"

class Doll
{
	DollAnimation _animation;
	CTexture _dollTexture;
	Vector2 _dollPosition;
	CRectangle _renderRect;
	float _scale = 0.03;
	bool _inversion;
	CRectangle _inversionRenderRect;
	
	class Field* _field;
	Block* _nextBlock = nullptr;

	bool _move;
	Vector2 _nextPosition;
	//1ブロック移動するのにかかるフレーム数
	const int _moveSpeed =40;
	int _moveCount;
	std::function<void()> _endMoveMethod;

	int _dustDumpValue,_waterDumpValue;
	bool _heldMop,_cleanAnimation;

	CSpriteMotionController	_motionController;
	const int wait = 3;
	int _motionCount;
	const int _textureValue = 30;
	Vector2 _dollTextureSize;
public:
	void Initialize();
	void ReLoad();
	void SetField(Field* field) { _field = field; }
	void SetPosition(Vector2 blockCenterPosisiton);
	void CalcuScale(float boxSizeY, float scale);
	void SetDumpValue(int dustDumpValue, int waterDumpValue);
	void SetEndMoveMethod(std::function<void()> method) { _endMoveMethod = method; }

	void Update();
	void SetNextBlock(Block* blcok);
	void Move();
	void EndMove();

	void Render();
	void Release();
private:
	void DollAnimationUpdate();
	void SetNextPosition();
	void ActionAccessories();
	void CleanDump();
	void SwitchToMop();
};