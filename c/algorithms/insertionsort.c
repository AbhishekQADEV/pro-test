#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unsorted[] = {5, 6, 4, 3, 9};
    int sorted[5];
    int a = 0;
    int b = 0;
    
    for (int i = 0; i < sizeof(unsorted) / sizeof(unsorted[0]); i++)
    {
        if (unsorted[i] < unsorted[b])
        {
            sorted[a] = unsorted[i];
            a++;
        }
    }
    
    return 0;
}