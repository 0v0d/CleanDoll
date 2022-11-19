#pragma once
#include	"Mof.h"
#include	"Wall.h"
#include	"BlockOnObject.h"

class Block
{
private:
	CTexture* _blockTexture = nullptr;
	Vector2 _position;
	const float _hitBoxScale = 0.2f;
	float _blockSizeX, _blockSizeY;
	float _scale;

	//周りのブロック　0:左, 1:上, 2:右, 3:下
	Block** _adjoinBlockArray;

	//0:左, 1:右, 2:中
	Wall* _wallArray = nullptr;
	const int _wallValue = 3;

	bool _passed;
	MofU32 _passedBlockColor = MOF_COLOR_RED;

	BlockOnObject _blockOnObject;
	int _x, _y;
public:
	void SetTexture(CTexture* blockTexture);
	void SetPosition(int x, int y, float topSpace);
	void SetScale(float scale) { _scale = scale; }
	void SetAdjoinBlockValue(int adjoinBlockValue);
	void SetAdjoinBlock(Block* block, int number);
	Block** GetAdjoinBlockArray() { return _adjoinBlockArray; }

	void CreateWall();
	void SetWall(CTexture* wallTexture, int number);
	void SetWallObject(CTexture* wallTexture, int number);

	void Initialize();
	void ReLoad();
	void Update();

	void SetPassedFlg(bool flg) { _passed = flg; }
	bool IsPassed() { return _passed; }

	void Render();

	void RenderBlcokOnObject();
	void Release();
	void Delete();

	Vector2 GetBlockSize() { return Vector2(_blockSizeX,_blockSizeY); }
	Vector2 GetCenterPosition() { return Vector2(_position.x + _blockTexture->GetWidth() * _scale /2, _position.y + _blockTexture->GetHeight() * _scale /2); }
	bool CheckMouseOnBlock(Vector2 mousePos);
	BlockOnObject* GetBlockOnObject() { return &_blockOnObject; }
};