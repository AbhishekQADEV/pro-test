#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void keylog()
{
    FILE *fPtr;
    fPtr = fopen("keylogger.txt", "a");

    char a;
    scanf(" %c", &a);

    if (a != '\n')
        fprintf(fPtr, "%c", a);

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;

    if (hour == 24)
        fclose(fPtr);
}

int main()
{
    keylog();
    return 0;
}