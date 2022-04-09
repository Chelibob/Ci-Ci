#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>


int asciiToI(char c)/*Функция преобразования буквы 16-тиричной системы в десятичное число*/
{
    int converter = 55;
    return (int)(toupper(c) - converter);
}


long htol(char arr[], size_t arr_size)
{
    int pos, digit, checkout, outNumber;
    digit = 0;/*Разряды числа*/
    pos = arr_size - 1; /*Позиция с которой начинаются символа числа*/
    outNumber = 0; /*Число, которое вернет функция*/
    /*Проверка является ли число 16-тиричным*/
    if(arr[0] == '0' && toupper(arr[1]) == 'X')
        checkout = 1;
    else
        checkout = 0;
    /*Если проверка пройдена переводим число в 10-ное, при переводе необходимо проверить 
    являются ли элементы массива, символами 16-тиричной системы счисления*/
    if(checkout){
        while(2 <= pos){
            if(isxdigit(arr[pos])){   /*Проверка на символ 16-тиричной системы счисления*/
                if (isdigit(arr[pos])){
                    outNumber += (long)pow(16.0,(double)digit) * (long)(arr[pos] - '0');
                    digit++;
                    --pos;
                }
                /*В этом блоке обрабатываются символьные значения, те что больше 9 - A, B, C ...*/
                else{
                    outNumber += (long)pow(16.0,(double)digit) * asciiToI(arr[pos]);
                    digit++;
                    --pos;
                }
                
            }
            /*Если в массиве попадается символ не соотвествующий 16-чной системе, функция выдаст ошибку и ответ -1*/
            else{
                printf("Enter incorrect number\n"); 
                outNumber = -1;
                break;
            }
        }
        return outNumber;
    }
    else
    {
        printf("Enter incorrect number\n");
        outNumber = - 1;
        return outNumber;
    }
    
}


int main()
{
    char s[] = {'0', 'x', '9', 'a', 'b'};
    size_t n = sizeof(s) / sizeof(s[0]);
    printf("%ld\n", htol(s,n));
    return 0;
}

