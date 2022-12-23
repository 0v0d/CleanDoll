#include "Trim.h"

std::string Trim::TrimString(std::string string)
{
	//引数の文字列がない
	if (!string.c_str())
	{
		return NULL;
	}
	//文字列の後ろから空白以外を見つけた次の位置に\0（終端）を設定する
	int end = strlen(string.c_str());
	while (--end >= 0)
	{
		if (string[end] != '\t' && string[end] != '\r' && string[end] != '\n' && string[end] != ' ')
		{
			break;
		}
	}
	string[end + 1] = '\0';
	//先頭から空白以外を見つけた位置のポインタを返す
	int buffer = 0;
	while (buffer < end)
	{
		if (string[buffer] != '\t' && string[buffer] != '\r' && string[buffer] != '\n' && string[buffer] != ' ')
		{
			return &string[buffer];
		}
		buffer++;
	}
	return string;
}
