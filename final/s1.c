#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *create_node(int val)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->data = val;

    return head;
}
Node *add_node(Node *head, Node *nw)
{
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    if (nw->data > 2 * (last->data))
    {
        last->next = nw;
        return head;
    }
    else
    {
        nw->next = head;
        return nw;
    }
}

void print_node(Node *head)
{
    while (head != NULL)
    {
        printf("%d-> ", head->data);
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    int num = 0;
    printf("> ");
    scanf("%d", &num);
    Node *head = create_node(num);
    while (1)
    {
        printf("> ");
        scanf("%d", &num);
        if (num < 0)
            break;
        head = add_node(head, create_node(num));
    }
    print_node(head);

    getch();
    return 0;
}