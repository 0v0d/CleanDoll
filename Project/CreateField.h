#pragma once
#include	"Field.h"
#include	"BlockManager.h"
#include	"Object.h"
#include	"Item.h"
#include	"Dump.h"

class CreateField
{
private:
	Field* _field;
	BlockManager* _blockManager;
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
};