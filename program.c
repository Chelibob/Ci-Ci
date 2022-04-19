#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>



unsigned setbits(unsigned x, int p, int n, int y)
{
    return (~((~(~0<<n))<<p)&x)|((~(~0<<n)&y)<<p);
    
}


unsigned invert(unsigned x, int p,int n){
    return (~x&(~(~0<<n)<<p)) | (x & ~(~(~0<<n)<<p));
}

int main(){
    printf("%d\n", setbits(31, 1, 2, 2));
    printf("%d\n", invert(31,2,2));
    return 0;
}

