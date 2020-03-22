#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef int (*FUNC)(int, int);

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

FUNC wrapper(const char op)
{
    switch (op)
    {
    case '+':
        return &add;
    case '-':
        return &sub;
    }
}

int main(int argc, char const *argv[])
{
    FUNC f;

    int x, y;
    printf("X: ");
    scanf("%d", &x);
    printf("Y: ");
    scanf("%d", &y);

    f = wrapper('+');
    printf("Toplama: %d\n", f(x, y));
    f = wrapper('-');
    printf("Cikarma: %d", f(x, y));

    getch();
    return 0;
}
