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


Node* create_node(int);
Node* push_node(Node*, Node*);
Node* delete_node(Node*, int);
void sort_node(Node*);

int main()
{
    Node* head = create_node(40);
    head = push_node(head, create_node(20));
    head = push_node(head, create_node(30));
    head = push_node(head, create_node(99));

    sort_node(head);
    getch();
}

void sort_node(Node* head)
{
    Node *i = head;
    Node *t;

    for(; i->next != head; i = i->next)
    {
        for (t = i->next; t != head; t = t->next)
        {
            if (i->data > t->data){
                int tmp = t->data;
                t->data = i->data;
                i->data = tmp;
            }
        }
    }
}

Node* delete_node(Node* head, int val)
{
    Node *tempt = head->next;
    Node* prev = head;

    while(tempt != head)
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
    return (Node*)NULL;
}


Node* push_node(Node* head, Node* add)
{
    Node *tempt = head->next;
    if (tempt == NULL)
    {
        add->next = head;
        head->next = add;
        
        return add;
    }
    while(tempt->next != head)
    {
        tempt = tempt->next;
    }
    tempt->next = add;;
    add->next = head;

    return add;
}

Node* create_node(int val)
{
    Node* nw = (Node*)malloc(sizeof(Node) * 1);
    nw->next = NULL;
    nw->data = val;

    return nw;
}