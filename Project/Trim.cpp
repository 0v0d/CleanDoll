#include "Trim.h"

std::string Trim::TrimString(std::string string)
{
	//�����̕����񂪂Ȃ�
	if (!string.c_str())
	{
		return NULL;
	}
	//������̌�납��󔒈ȊO�����������̈ʒu��\0�i�I�[�j��ݒ肷��
	int end = strlen(string.c_str());
	while (--end >= 0)
	{
		if (string[end] != '\t' && string[end] != '\r' && string[end] != '\n' && string[end] != ' ')
		{
			break;
		}
	}
	string[end + 1] = '\0';
	//�擪����󔒈ȊO���������ʒu�̃|�C���^��Ԃ�
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
