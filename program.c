#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>




int main()
{
    int c, lim;
    lim = 1000;
    char s [lim];
    for(int i = 0; (c = getchar()) != EOF; ++i)
    {
        if(i < lim -1)
        {
            if(c != '\n')
            {
                s[i] = c;
            }
        }
    }
    printf("\n%s", s);
    return 0;
}

