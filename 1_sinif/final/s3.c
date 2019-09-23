#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

Node *cnode(int data)
{
    Node *nw = (Node *)malloc(sizeof(Node));
    nw->data = data;
    nw->next = NULL;
    nw->prev = NULL;

    return nw;
}

Node *pshnode(Node *head, Node *nw)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = nw;
    nw->prev = head;

    return nw;
}

int main(int argc, char const *argv[])
{
    // sayilar.txt yi random doldur
    FILE *fp = fopen("sayilar.txt", "w");

    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        fprintf(fp, "%d ", rand() % 200);
    }
    fclose(fp);

    // oku
    FILE *fpr = fopen("sayilar.txt", "r");
    FILE *fpw = fopen("sayilarters.txt", "w");

    int num;
    fscanf(fpr, "%d ", &num);
    Node *head = cnode(num);

    for (int i = 0; i < 100; i++)
    {
        fscanf(fpr, "%d ", &num);
        pshnode(head, cnode(num));
    }

    // head basta onu son elemana al cunku prev ile geri gidecegiz
    while (head->next != NULL)
    {
        head = head->next;
    }

    // ters yaz
    while (head != NULL)
    {
        fprintf(fpw, "%d ", head->data);
        head = head->prev;
    }
    fclose(fpr);
    fclose(fpw);
    getch();
    return 0;
}