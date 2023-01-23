#include "CreateField.h"

CreateField::CreateField() {
	_mapTextureArray.LineXValue = 1;
	_objectTextureArray.LineXValue = 1;
	_itemTextureArray.LineXValue = 1;
	_mopTextureArray.LineXValue = 1;
	_dustDumpTextureArray.LineXValue = 1;
	_waterDumpTextureArray.LineXValue = 1;
	_wallTextureArray.LineXValue = 3;
	_wallObjectTextureArray.LineXValue = 2;
}

void CreateField::Initialize()
{
	LoadStageSelectData();
}

void CreateField::LoadStageSelectData()
{
	_contactFile.OpenFile("StageManager.txt");
	int stageValue = _contactFile.GetValue(true);
	std::string* stageFileNameArray = new std::string[stageValue];
	for (int i = 0;i < stageValue;i++)
	{
		stageFileNameArray[i] = _contactFile.GetString(false);
	}
	_contactFile.CloseFile();

	_barManager->CreateBarArray(stageValue);
	for (int i = 0;i < stageValue;i++)
	{
		_contactFile.OpenFile(stageFileNameArray[i]);

		std::string previewTextureName = _contactFile.GetString(true);
		std::string  barTextureName = _contactFile.GetString(false);
		int  difficulty = _contactFile.GetValue(false);
		std::string stageDataTextName = _contactFile.GetString(false);

		_barManager->SetBarStatu(i, previewTextureName, barTextureName, difficulty, stageDataTextName);
		_contactFile.CloseFile();
	}

	delete[] stageFileNameArray;
}

void CreateField::LoadStage(std::string stageName)
{
	Delete();
	_contactFile.OpenFile(stageName.c_str());

	_blockValueX = _contactFile.GetValue(true);
	_blockValueY = _contactFile.GetValue(false);

	_setFieldData.SetFieldStatu(_blockValueX, _blockValueY);

	//マップ
	LoadTexture(&_mapTextureArray);
	_setFieldData.SetBlockData(_mapTextureArray.textureArray, _chipDataArray);
	DeleteChipData(&_mapTextureArray);

	//オブジェクト
	LoadTexture(&_objectTextureArray);
	_setFieldData.SetObjectData(_objectTextureArray.textureArray, _chipDataArray);
	DeleteChipData(&_objectTextureArray);

	//アイテム
	LoadTexture(&_itemTextureArray);
	_setFieldData.SetItemData(_itemTextureArray.textureArray, _chipDataArray, true);
	DeleteChipData(&_itemTextureArray);

	//モップ
	LoadTexture(&_mopTextureArray);
	_setFieldData.SetItemData(_mopTextureArray.textureArray, _chipDataArray, false);
	DeleteChipData(&_mopTextureArray);

	//埃
	LoadTexture(&_dustDumpTextureArray);
	_setFieldData.SetDumpData(_dustDumpTextureArray.textureArray, _chipDataArray, true);
	DeleteChipData(&_dustDumpTextureArray);

	//水汚れ
	LoadTexture(&_waterDumpTextureArray);
	_setFieldData.SetDumpData(_waterDumpTextureArray.textureArray, _chipDataArray, false);
	DeleteChipData(&_waterDumpTextureArray);

	//壁
	LoadTexture(&_wallTextureArray);
	_setFieldData.SetWallData(_wallTextureArray.textureArray, _chipDataArray, _wallTextureArray.LineXValue);
	DeleteChipData(&_wallTextureArray);

	//壁用オブジェクト
	LoadTexture(&_wallObjectTextureArray);
	_setFieldData.SetWallObjectkData(_wallObjectTextureArray.textureArray, _chipDataArray, _wallObjectTextureArray.LineXValue);
	DeleteChipData(&_wallObjectTextureArray);

	LoadDoll();
	LoadCoin();

	_contactFile.CloseFile();
}

void CreateField::LoadTexture(TextureArray* textureArray)
{
	NewChipData(textureArray);

	textureArray->textureValue = atoi(strtok(NULL, ","));
	textureArray->textureArray = new CTexture[textureArray->textureValue];

	for (int i = 0; i < textureArray->textureValue; i++) {
		if (!textureArray->textureArray[i].Load(strtok(NULL, ","))) return;
	}

	for (int y = 0; y < _blockValueY; y++) {
		for (int x = 0; x < _blockValueX * textureArray->LineXValue; x++)
		{
			_chipDataArray[x][y] = atoi(strtok(NULL, ","));
		}
	}
}

void CreateField::LoadDoll()
{
	for (int y = 0; y < _blockValueY; y++)
	{
		for (int x = 0; x < _blockValueX; x++)
		{
			if (_contactFile.GetValue(false) != 0)
			{
				_setFieldData.SetDoll(x, y);
			}
		}
	}
}

void CreateField::LoadCoin() {
	int stageNumber = _barManager->GetCurrentStageNumber();
	//-1はチュートリアル
	if (stageNumber != -1 && _barManager->GetBar(stageNumber)->IsGetCoin()) {
		_setFieldData.SetCoin(0, 0, true);
		return;
	}

	for (int y = 0; y < _blockValueY; y++)
	{
		for (int x = 0; x < _blockValueX; x++)
		{
			if (_contactFile.GetValue(false) != 0)
			{
				_setFieldData.SetCoin(x, y, false);
			}
		}
	}
}

void CreateField::NewChipData(TextureArray* textureArray)
{
	_chipDataArray = new char* [_blockValueX * textureArray->LineXValue];
	for (int i = 0; i < _blockValueX * textureArray->LineXValue; i++)_chipDataArray[i] = new char[_blockValueY];

	for (int y = 0; y < _blockValueY; y++) {
		for (int x = 0; x < _blockValueX * textureArray->LineXValue; x++)
			_chipDataArray[x][y] = 0;
	}
}

void CreateField::DeleteChipData(TextureArray* textureArray)
{
	for (int i = 0; i < _blockValueX * textureArray->LineXValue; i++) delete[] _chipDataArray[i];
	delete[] _chipDataArray;
}

void CreateField::Delete()
{
	DeleteTextureArray(&_mapTextureArray);
	DeleteTextureArray(&_objectTextureArray);
	DeleteTextureArray(&_itemTextureArray);
	DeleteTextureArray(&_mopTextureArray);
	DeleteTextureArray(&_dustDumpTextureArray);
	DeleteTextureArray(&_waterDumpTextureArray);
	DeleteTextureArray(&_wallTextureArray);
	DeleteTextureArray(&_wallObjectTextureArray);
}

void CreateField::DeleteTextureArray(TextureArray* textureArray)
{
	if (textureArray->textureValue == 0)return;

	for (int i = 0; i < textureArray->textureValue; i++) textureArray->textureArray[i].Release();
	delete[] textureArray->textureArray;
	textureArray->textureArray = nullptr;

	textureArray->textureValue = 0;
}

void CreateField::Release()
{
	Delete();
}