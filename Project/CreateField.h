#pragma once
#include	"Mof.h"
#include	"string"
#include	"SetFieldData.h"
#include	"ContactFile.h"
#include	"BarManager.h"

struct TextureArray
{
	int textureValue;
	CTexture* textureArray = nullptr;
	//テキストファイルのx軸の倍率
	int LineXValue;
};

class CreateField
{
	SetFieldData _setFieldData;
	ContactFile _contactFile;

	char** _chipDataArray;

	TextureArray _mapTextureArray;
	TextureArray _objectTextureArray;
	TextureArray _itemTextureArray;
	TextureArray _galleryTextureArray;
	TextureArray _mopTextureArray;
	TextureArray _dustDumpTextureArray;
	TextureArray _waterDumpTextureArray;
	TextureArray _wallTextureArray;
	TextureArray _wallObjectTextureArray;
	int _blockValueX, _blockValueY;

	BarManager* _barManager;

public:
	~CreateField() { Release(); }
	void Initialize();
	void SetBarManager(BarManager* barManager) { _barManager = barManager; }

	void LoadStage(std::string stageName);
	void LoadDoll();

	void Release();
	void Delete();

	SetFieldData* GetSetFieldData() { return &_setFieldData; }

private:
	void LoadStageSelectData();

	void LoadTexture(TextureArray* textureArray);
	void SetDoll(int x, int y);
	void NewChipData(TextureArray* textureArray);
	void DeleteChipData(TextureArray* textureArray);
	void DeleteTextureArray(TextureArray* textureArray);
};