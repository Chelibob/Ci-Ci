#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>



void squeeze(char s1[], char s2[]){
    int i,j,k,check;
    check = 0;
    for(i = j = 0; s1[i] != '\0'; i++){
        for(k = 0; s2[k] != '\0'; k++){
            if (s1[i] == s2[k]){
                check = 1;
                break;
            }
            else
                check = 0;
        }
        if(!check)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}


int main(){
    char s1[] = "afrfora";
    char s2[] = "frodl";
    squeeze(s1,s2);
    printf("%s\n",s1);
    return 0;
}

