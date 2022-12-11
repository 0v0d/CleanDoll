#include "ContactFile.h"

void ContactFile::OpenFile(std::string fileName)
{

    _file = fopen(fileName.c_str(), "rt");
    if (_file == NULL) return;

    fseek(_file, 0, SEEK_END);
    _fileSize = ftell(_file);
    fseek(_file, 0, SEEK_SET);
    _buffer = new char[_fileSize + 1];
    _fileSize = fread(_buffer, 1, _fileSize, _file);
    _buffer[_fileSize] = '\0';
}

void ContactFile::CloseFile()
{
    fclose(_file);
    delete _buffer;
}

int ContactFile::GetValue(bool firstContact)
{
    return firstContact ? atoi(strtok(_buffer, ",")) : atoi(strtok(NULL, ","));
}

std::string ContactFile::GetString(bool firstContact)
{
    return firstContact ? strtok(_buffer, ",") : strtok(NULL, ",");
}