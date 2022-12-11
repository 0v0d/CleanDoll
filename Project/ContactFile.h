#pragma once
#include	"Mof.h"
#include	"string"
class ContactFile
{
	FILE* _file;
	char* _buffer;
	long _fileSize;
public:
	void OpenFile(std::string fileName);
	void CloseFile();

	int GetValue(bool firstContact);
	std::string GetString(bool firstContact);
};