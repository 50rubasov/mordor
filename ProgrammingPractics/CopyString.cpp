#include "stdafx.h"
#include "CopyString.h"
/*---------------------����������� ������------------------------------*/
void CopyString(char* string1, const char* string2)		//����������� ������ //todo �������� � ������ �� �������� //done
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}