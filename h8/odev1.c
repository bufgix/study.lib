#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/*
    Bi taraflarım yırdıldı yazarken
    direk kopyalayıp kullanan Algo2 den gecemez ins

    Bufgix
*/


const char *FILEPATH = "h8/bir.txt"; // programı calıstırınca h8 diye bi klasor olacak
                                    // onun icinde dosya. Aglamayin sonra

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node Node;


// Funciton dec;
Node* create_node(int);
Node* push(Node*, Node*);
void sort_node(Node*);
void print_node(Node*);
void generate_file();
// End

int main()
{
    generate_file();

    FILE *fp = fopen(FILEPATH, "r");
    int num;

    fscanf(fp, "%d ", &num);
    Node* head = create_node(num);

    do{
        fscanf(fp, "%d ", &num);
        push(head, create_node(num));
    }while(!feof(fp));
    fclose(fp);

    print_node(head);
    sort_node(head);
    printf("\n\n");
    print_node(head);

    getch();
}

void sort_node(Node* head)
{
    Node* i = head;
    Node* j;

    for(; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }

}

Node* push(Node* head, Node* add)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = add;
    add->prev = head;
    
    return add;
}

Node* create_node(int num)
{
    Node *nw_node = (Node*)malloc(sizeof(Node));
    nw_node->data = num;
    nw_node->next = NULL;
    nw_node->prev = NULL;
    
    return nw_node;"";
}

void generate_file()
{
    srand(time(NULL));
    FILE *fp = fopen(FILEPATH, "w");

    for (int i = 0; i < 30; i++)
    {
        fprintf(fp, "%d ", rand() % 200);
    }
    fclose(fp);
}

void print_node(Node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
    
}