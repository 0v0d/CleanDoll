#pragma once
#include	"Mof.h"
#include	"string"
#include	"CreateField.h"
#include	"BarManager.h"

struct TextureArray
{
	int textureValue;
	CTexture* textureArray = nullptr;
	//テキストファイルのx軸の倍率
	int LineXValue;
};

class ContactFile
{
	CreateField* _createField;
	FILE* _file;
	char* _buffer;
	long _fileSize;
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
	~ContactFile() { Release(); }
	void Initialize();
	void SetCreateField(CreateField* createField) { _createField = createField; }
	void SetBarManager(BarManager* barManager) { _barManager = barManager; }

	void LoadStage(std::string stageName);
	void LoadDoll();

	void Release();
	void Delete();

	CreateField* GetCreateField() { return _createField; }

private:
	void LoadStageSelectData();

	void LoadTexture(TextureArray* textureArray);
	void SetDoll(int x, int y);
	void NewChipData(TextureArray* textureArray);
	void DeleteChipData(TextureArray* textureArray);
	void DeleteTextureArray(TextureArray* textureArray);

	void OpenFile(std::string fileName);
	void CloseFile();
	int GetValue(bool firstContact);
	std::string GetString(bool firstContact);
};