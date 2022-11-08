#pragma once
#include	"BlockManager.h"
#include	"Field.h"
#include	"Object.h"
#include	"Item.h"
#include	"Dump.h"

class CreateField
{
private:
	BlockManager* _blockManager;
	Field* _field;
	int _blockValueX, _blockValueY;
public:
	void SetField(Field* field);
	void SetFieldStatu(int blockValueX, int blockValueY);
	void SetBlockData(CTexture* TextureArray, char** dataArray);
	void SetObjectData(CTexture* TextureArray, char** dataArray);
	void SetItemData(CTexture* TextureArray, char** dataArray,bool isCandy);
	void SetDumpData(CTexture* TextureArray, char** dataArray,bool isDustDump);
	void SetWallData(CTexture* TextureArray, char** dataArray,int lineValueX);
	void SetWallObjectkData(CTexture* TextureArray, char** dataArray, int lineValueX);
	void SetDoll(int x, int y);

private:
	void SetBlockManager() { _blockManager = _field->GetBlockManager(); }
};