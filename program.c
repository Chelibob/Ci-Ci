#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>





void lower(char s[]){
    for(int i = 0; s[i] != '\0'; i++)
        (isupper(s[i])) ? s[i] = tolower(s[i]): s[i];
}


int main(){
    char s1[] = "HeLLo World";
    lower(s1);
    printf("%s\n",s1);
    return 0;
}

