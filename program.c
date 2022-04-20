#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>



unsigned setbits(unsigned x, int p, int n, int y)
{
    return (~((~(~0<<n))<<p)&x)|((~(~0<<n)&y)<<p);
    
}


unsigned invert(unsigned x, int p,char n){
    return (~x&(~(~0<<n)<<p)) | (x & ~(~(~0<<n)<<p));
}

int binary_search(char s[], size_t arrsize, char item){
    int low = 0;
    int high = arrsize;
    while(low <= high){
        int mid = (low+high)/2;
        int guess = s[mid];
        if(guess == item)
            return mid;
        if(guess > item)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(){
    char s[] = "13579";
    size_t arrsize = sizeof(s)/sizeof(s[0]);
    printf("%d\n", binary_search(s,arrsize,'3'));
    return 0;
}

