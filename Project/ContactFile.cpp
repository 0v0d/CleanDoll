#include "ContactFile.h"

void ContactFile::Initialize() {
	_mapTextureArray.LineXValue = 1;
	_objectTextureArray.LineXValue = 1;
	_itemTextureArray.LineXValue = 1;
	_galleryTextureArray.LineXValue = 1;
	_mopTextureArray.LineXValue = 1;
	_dustDumpTextureArray.LineXValue = 1;
	_waterDumpTextureArray.LineXValue = 1;
	_wallTextureArray.LineXValue = 3;
	_wallObjectTextureArray.LineXValue = 2;
}

void ContactFile::LoadStage(std::string stageName) {
	//削除
	Delete();
	OpenFile(stageName.c_str());

	_blockValueX = atoi(strtok(_buffer, ","));
	_blockValueY = atoi(strtok(NULL, ","));

	_createField.SetFieldStatu(_blockValueX, _blockValueY);

	//マップ
	LoadTexture(&_mapTextureArray);
	_createField.SetBlockData(_mapTextureArray.textureArray, _chipDataArray);
	DeleteChipData(&_mapTextureArray);

	//オブジェクト
	LoadTexture(&_objectTextureArray);
	_createField.SetObjectData(_objectTextureArray.textureArray,_chipDataArray);
	DeleteChipData(&_objectTextureArray);

	//アイテム
	LoadTexture(&_itemTextureArray);
	_createField.SetItemData(_itemTextureArray.textureArray, _chipDataArray,true);
	DeleteChipData(&_itemTextureArray);

	//ギャラリー
	LoadTexture(&_galleryTextureArray);
	_createField.SetItemData(_galleryTextureArray.textureArray, _chipDataArray, false);
	DeleteChipData(&_galleryTextureArray);

	//モップ
	LoadTexture(&_mopTextureArray);
	_createField.SetItemData(_mopTextureArray.textureArray, _chipDataArray, false);
	DeleteChipData(&_mopTextureArray);

	//埃
	LoadTexture(&_dustDumpTextureArray);
	_createField.SetDumpData(_dustDumpTextureArray.textureArray,_chipDataArray,true);
	DeleteChipData(&_dustDumpTextureArray);

	//水汚れ
	LoadTexture(&_waterDumpTextureArray);
	_createField.SetDumpData(_waterDumpTextureArray.textureArray, _chipDataArray, false);
	DeleteChipData(&_waterDumpTextureArray);

	//壁
	LoadTexture(&_wallTextureArray);
	_createField.SetWallData(_wallTextureArray.textureArray,_chipDataArray,_wallTextureArray.LineXValue);
	DeleteChipData(&_wallTextureArray);

	//壁用オブジェクト
	LoadTexture(&_wallObjectTextureArray);
	_createField.SetWallObjectkData(_wallObjectTextureArray.textureArray,_chipDataArray, _wallObjectTextureArray.LineXValue);
	DeleteChipData(&_wallObjectTextureArray);

	LoadDoll();

	CloseFile();
}

void ContactFile::LoadTexture(TextureArray* textureArray) {

	NewChipData(textureArray);

	textureArray->textureValue = atoi(strtok(NULL, ","));
	if (textureArray->textureValue == 0) return;
	textureArray->textureArray = new CTexture[textureArray->textureValue];

	for (int i = 0;i < textureArray->textureValue; i++) {
		if (!textureArray->textureArray[i].Load(strtok(NULL, ",")))return;
	}

	for (int y = 0;y < _blockValueY;y++) {
		for (int x = 0;x < _blockValueX * textureArray->LineXValue;x++)
			_chipDataArray[x][y] = atoi(strtok(NULL, ","));
	}
}

void ContactFile::LoadDoll() {

	for (int y = 0;y < _blockValueY;y++){
		for (int x = 0; x < _blockValueX; x++) {
			if (atoi(strtok(NULL, ",")) != 0) {
				SetDoll(x, y);
				return;
			}
		}
	}
}

void ContactFile::SetDoll(int x,int y) {
	_createField.SetDoll(x, y);
}

void ContactFile::OpenFile(std::string fileName) {

	_file = fopen(fileName.c_str(), "rt");
	if (_file == NULL) return;

	fseek(_file, 0, SEEK_END);
	_fileSize = ftell(_file);
	fseek(_file, 0, SEEK_SET);

	_buffer = (char*)malloc(_fileSize + 1);
	_fileSize = fread(_buffer, 1, _fileSize, _file);
	_buffer[_fileSize] = '\0';
}

void ContactFile::CloseFile() {

	fclose(_file);
	free(_buffer);
}

int ContactFile::GetValue(bool firstContact) {
	return firstContact ? atoi(strtok(_buffer, ",")) : atoi(strtok(NULL, ","));
}

std::string ContactFile::GetString(bool firstContact) {
	return firstContact ? strtok(_buffer, ",") : strtok(NULL, ",");
}


void ContactFile::Delete() {
	DeleteTextureArray(&_mapTextureArray);
	DeleteTextureArray(&_objectTextureArray);
	DeleteTextureArray(&_itemTextureArray);
	DeleteTextureArray(&_galleryTextureArray);
	DeleteTextureArray(&_mopTextureArray);
	DeleteTextureArray(&_dustDumpTextureArray);
	DeleteTextureArray(&_waterDumpTextureArray);
	DeleteTextureArray(&_wallTextureArray);
	DeleteTextureArray(&_wallObjectTextureArray);
}

void ContactFile::DeleteTextureArray(TextureArray* textureArray) {
	if (textureArray->textureValue == 0)return;

	for (int i = 0;i < textureArray->textureValue;i++) textureArray->textureArray[i].Release();
	delete[] textureArray->textureArray;
	textureArray->textureArray = nullptr;

	textureArray->textureValue = 0;
}

void ContactFile::NewChipData(TextureArray* textureArray) {

	_chipDataArray = new char* [_blockValueX * textureArray->LineXValue];
	for (int i = 0;i < _blockValueX * textureArray->LineXValue;i++)_chipDataArray[i] = new char[_blockValueY];
}

void ContactFile::DeleteChipData(TextureArray* textureArray) {

	for (int i = 0;i < _blockValueX * textureArray->LineXValue;i++) delete[] _chipDataArray[i];
	delete[] _chipDataArray;
}

void ContactFile::Release() {

	Delete();
}