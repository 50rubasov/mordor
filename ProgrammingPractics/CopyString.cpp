#include "stdafx.h"
#include "CopyString.h"
/*---------------------Копирование строки------------------------------*/
void CopyString(char* string1, const char* string2)		//копирование строки //todo вытащить в модуль со строками //done
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}