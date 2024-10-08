#include <stdio.h>
#include <stdlib.h>

void print_arr(int *ptr, int size)
{
    putchar('[');
    for(int i = 0; i < size; i++)
    {
        printf("%d", ptr[i]);
        if(i < size - 1)
            putchar(',');
    }
    printf("]\n");
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int *find_min(int *ptr, int size)
{
    int *min = ptr;
    for(int i = 1; i < size; i++)
    {
        if(ptr[i] < *min)
            min = &ptr[i];
    }
    return min;
}

void selection_sort(int *ptr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int *min = find_min(ptr + i, size - i);
        if(*min < ptr[i])
            swap(min, &ptr[i]);
    }
}

void fill(char **av, int *ptr, int size)
{
    for(int i = 0; i < size; i++)
    {
        ptr[i] = atoi(av[i + 2]);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        puts("Usage: ./your-executable-name [array size] [array]");
        puts("Example: ./your-executable-name 3 2 1 0");
        return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);
    if(size == 0)
    {
        puts("Error: size of array can't be 0");
        return EXIT_FAILURE;
    }
    int *arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL)
        return EXIT_FAILURE;
    fill(argv, arr, size);

    printf("Before sorting: ");
    print_arr(arr, size);

    selection_sort(arr, size);

    printf("After sorting:  ");
    print_arr(arr, size);

    free(arr);
    return EXIT_SUCCESS;
}