#pragma once
#include	"Mof.h"
#include	"Block.h"
#include	"vector"
#include	"functional"
#include "DollMopAnimation.h"
#include "DollBroomAnimation.h"

class Doll
{
	DollMopAnimation _mopAnimation;
	DollBroomAnimation _broomAnimation;
	CTexture _dollTexture;
	Vector2 _dollPosition;
	CRectangle _renderRect;
	float _scale;
	bool _inversion;
	CRectangle _inversionRenderRect;

	class Field* _field;
	Block* _nextBlock = nullptr;

	bool _move;
	Vector2 _nextPosition;
	//1ブロック移動するのにかかるフレーム数
	const int _framePBlock = 40;
	//倍率をかけた速さ
	float _moveSpeed;
	int _moveCount;
	std::function<void()> _endMoveMethod;

	int _dustDumpValue, _waterDumpValue;
	bool _holdMop, _animationflg;
	bool _getCoin;

	int _motionCount;
	const int _textureValue = 30;
	Vector2 _dollTextureSize;

	CSoundBuffer HokoriSound;
	CSoundBuffer MopSound;
public:
	void Initialize();
	void LoadTexture();
	void ReLoad();
	void SetField(Field* field) { _field = field; }
	void SetPosition(Vector2 blockCenterPosisiton);
	void CalcuScale(float boxSizeY, float scale);
	void SetDumpValue(int dustDumpValue, int waterDumpValue);
	void SetEndMoveMethod(std::function<void()> method) { _endMoveMethod = method; }
	void CalcuSpeed(float speedFactor) { _moveSpeed = _framePBlock / speedFactor; }

	void Update();
	void SetNextBlock(Block* blcok);
	void Move();
	void EndMove();

	void Render();
	void Release();

	bool IsGetCoin() { return _getCoin; }
private:
	void DollAnimationUpdate();
	void SetNextPosition();
	void ActionAccessories();
	void CleanDump();
	void SwitchToMop();
	void CollectCandy();
	void SetMoveAnimation();
	void Inversion();
};