#include <stdio.h>

struct Person
{
    char name[20];
};


int main(int argc, char const *argv[])
{
    struct Person p;
    scanf("%s", &p.name);
    printf("%s\n", p.name);
    return 0;
}
