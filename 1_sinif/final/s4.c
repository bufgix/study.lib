#include <stdio.h>
#include <conio.h>
#include <string.h>

void lrs(char *src, int shift)
{

    char newstr[2];
    for (int i = 0; i < shift; i++)
    {
        char first_char = src[0];
        for (int j = 0; j < strlen(src); j++)
        {
            src[j] = src[j + 1];
        }
        newstr[0] = first_char;
        newstr[1] = '\0';
        strcat(src, newstr);
    }
}

int main(int argc, char const *argv[])
{
    char name[20] = "Omer";
    lrs(name, 5);
    printf("%s", name);
    getch();
    return 0;
}