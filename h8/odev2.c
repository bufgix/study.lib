#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Bi taraflarım yırdıldı yazarken
    direk kopyalayıp kullanan Algo2 den gecemez ins

    Bufgix
*/

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

Node *create_node(int);
Node *push_node(Node *, Node *);
Node *delete_node(Node *, int);
void sort_node(Node *);
void print_node(Node *);

int main()
{
    /*Node* head = create_node(40);
    head = push_node(head, create_node(20));
    head = push_node(head, create_node(30));
    head = push_node(head, create_node(99));

    sort_node(head);*/

    Node *head;
    char *help_text = (char *)"1 - EKLE\n2 - SIL\n3 - SIRALA(Bu islem geri alinmaz)\n4 - YAZDIR\n\n[>] ";
    int inital, num;
    printf("Once bir deger girin. Bu listeini ilk elemani olacak\nDeger: ");
    scanf("%d", &inital);
    head = create_node(inital);
    while (1)
    {
        printf("%s", help_text);
        scanf("%d", &inital);

        if (inital == 1)
        {
            printf(">> ");
            scanf("%d", &num);
            push_node(head, create_node(num));
            printf("Eklendi\n");
        }
        else if (inital == 2)
        {
            printf(">> ");
            scanf("%d", &num);
            head = delete_node(head, num);
            printf("Silindi\n");
        }
        else if (inital == 3)
        {
            sort_node(head);
            print_node(head);
        }
        else if (inital == 4)
        {
            print_node(head);
        }
    }
    getch();
}

void sort_node(Node *head)
{
    Node *i = head;
    Node *t;

    for (; i->next != head; i = i->next)
    {
        for (t = i->next; t != head; t = t->next)
        {
            if (i->data > t->data)
            {
                int tmp = t->data;
                t->data = i->data;
                i->data = tmp;
            }
        }
    }
}

Node *delete_node(Node *head, int val)
{
    Node *tempt = head->next;
    Node *prev = head;

    while (tempt != head)
    {
        if (tempt->data == val)
        {
            prev->next = tempt->next;
            free(tempt);
            return head;
        }
        prev = tempt;
        tempt = tempt->next;
    }
    if (head->data == val)
    {
        prev->next = head->next;
        free(head);
        return prev;
    }
    return (Node *)NULL;
}

Node *push_node(Node *head, Node *add)
{
    Node *tempt = head->next;
    if (tempt == NULL)
    {
        add->next = head;
        head->next = add;

        return add;
    }
    while (tempt->next != head)
    {
        tempt = tempt->next;
    }
    tempt->next = add;
    add->next = head;

    return add;
}

Node *create_node(int val)
{
    Node *nw = (Node *)malloc(sizeof(Node) * 1);
    nw->next = NULL;
    nw->data = val;

    return nw;
}

void print_node(Node *head)
{
    Node *tempt = head->next;
    if (tempt == NULL)
    {
        printf("%d -> \n", head->data);
        return;
    }
    printf("%d -> ", head->data);

    while (tempt != head)
    {
        printf("%d -> ", tempt->data);
        tempt = tempt->next;
    }

    printf("\n");
}