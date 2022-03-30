#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PRINTLEN 5 /* максимальный размер вводимой строки */
#define ARRLEN 1000 /*Длина массива*/
#define TABSTOP 8 /*Фиксированное количество позиций для таба*/

int myGetLine(char linef[], int MAXLINE); 
void copy(char to[], char fromf[]); 

/*Функция для получения строки*/
int myGetLine(char s[], int limit)
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
void detab(char input[], int len)
{
    int i, j, spCount;
    spCount = 0;
    j = 0;
    char bufferArr[ARRLEN];
    for(i = 0; i < len; ++i)
    {
        bufferArr[i] = input[i];
    }
    for(i = 0; i < len; i++)
    {
        if(bufferArr[i] == '\t'){
            spCount = TABSTOP - (j % TABSTOP);
            while(spCount > 0)
            {
                input[j] = '*';
                ++j;
                --spCount;
            }
        }
        else
        {
            input[j] = bufferArr[i];
            ++j;
        }
    }
}




int main()
{
    int len;
    char line[ARRLEN];
    char copyLine[ARRLEN];
    char resultLine[ARRLEN];
    int pos = 0;
    while ((len = myGetLine(line,ARRLEN)) > 0)
    {
        if(line[0] != '\n')
        {
            copy(line, copyLine);
            detab(copyLine,len);
            pos = pasting(copyLine, resultLine, pos);
        }
    }
    resultLine[pos+1] = '\0';
    printf("%s", resultLine);
    return 0;
}
