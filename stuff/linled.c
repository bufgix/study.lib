#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    Node *next;
} Node;

Node *newNode(int newData)
{
    Node *nw = (Node *)malloc(sizeof(Node));
    nw->data = newData;
    nw->next = NULL;

    return nw;
}

int main(int argc, char const *argv[])
{
    Node *yeni = newNode(12);

    return 0;
}
