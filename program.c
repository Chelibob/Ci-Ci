#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>



int any(char s1[], char s2[]){
    int i,j;
    for(j = 0; s2[j] != '\0'; j++){
        for(i = 0; s1[i] != '\0'; i++){
            if(s2[j] == s1[i])
                return i;
        }
    }
    return -1;
}


int main(){
    char s1[] = "Hello, world";
    char s2[] = "gtu";
    printf("First entry: %d\n",any(s1,s2));
    return 0;
}

