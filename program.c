#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PRINTLEN 5 /* максимальный размер вводимой строки */
#define ARRLEN 1000 /*Длина массива*/

/*Функция для получения строки*/
int getline(char s[], int limit)
{
	int c,i;
	for (i = 0; i < (limit - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/*Функция копирования массива*/
void copy (char from[], char to[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
/*Функция для составления результирующего массива*/
int pasting(char from[], char to[], int pos)
{
	int i = 0;
	while ((to[pos] = from[i]) != '\n' && (to[pos] = from[i]) != '\0')
	{
		++i;
		++pos;
	}
	++pos;
	to[pos] = '\n';
	return pos;
}

/*Функция редактирования массива*/
void editLine(char input[], int len)
{
	int i, sc, index;
	for(i = 0, sc = 0, index = 0; i < len; ++i)
	{
		if (input[i] == ' ' || input[i] == '\t')
			++sc;
		else
		{
			if(sc > 0 && index != 0)
			{
				input[index] = ' ';
				++index;
			}
			input[index] = input[i];
			++index;
			sc = 0;
		}
	}
	input[index] = '\0';
}

int main()
{
    int len;
	char line[ARRLEN]; //исходный массив
	char copyLine[ARRLEN];//массив для копирования
	char resultLine[ARRLEN];//результирующий массив
	int pos = 0;//Позиция для начала вставки в результирующий массив
	while ((len = getline(line, ARRLEN)) > 0)
		if(line[0] != '\n')
		{
			copy(line, copyLine);
			editLine(copyLine,len);
			pos = pasting(copyLine, resultLine, pos);
		}
	resultLine[pos + 1] = '\0';//Добавления нуля в конец результирующего массива в конец
	printf("%s", resultLine);
    return 0;
}
