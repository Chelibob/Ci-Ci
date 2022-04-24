#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>

#define ARRSIZE 1000



void escape(char t[],char s[]){
    int i,j;
    for(j = i = 0; t[i] != '\0'; i++,j++){
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j] = 't';
            break;
        default:
            s[j] = t[i];
            break;
        }
    }
    s[j] = '\0';
}


void unescape(char t[],char s[]){
    int i,j;
    for(i = j = 0; t[i] != '\0'; i++, j++){
        switch (t[i] + t[i+1]){
        case '\\' + 'n':
            s[j] = '\n';
            i++;
            break;
        case '\\' + 't':
            s[j] = '\t';
            i++;
            break;
        default:
            s[j] = t[i];
            break;
        }
    }
    s[j] = '\0';
}




int main(){
    int c, i;
    char s1[ARRSIZE];
    char s2[ARRSIZE];
    char s3[ARRSIZE];
    for(i = 0; (c = getchar()) != EOF; i++)
        s1[i] = c;
    s1[i] = '\0';
    printf("%s\n", s1);
    escape(s1,s2);
    printf("%s\n", s2);
    unescape(s2,s3);
    printf("%s\n", s3);
    return 0;
}

