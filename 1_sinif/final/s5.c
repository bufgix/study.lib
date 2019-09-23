#include <stdio.h>
#include <conio.h>

// Binary olarak ekrana yazan fonksyon
void printbin(int num)
{
    int size = sizeof(int) * 8 - 1; // 31;
    for (; size >= 0; size--)
    {
        if (num >> size & 1)
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }
        if (size % 4 == 0)
            putchar(' ');
    }
    printf("\n");
}

int wbit(int num, int index)
{
    if (num & 1 << index - 1)
        return 1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    int num;
    while (1)
    {
        printf("> ");
        scanf("%d", &num);
        if (wbit(num, 5) == 0)
        {
            printf("%d\n", num >> 1);
        }
        else
        {
            printf("%d\n", num << 1);
        }
    }

    getch();
    return 0;
}