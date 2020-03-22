#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[200];
    float imdb;
    Node *next;
} Node;

// Yeni node
Node *initNode(const char *name, float imdb)
{
    Node *nw = (Node *)malloc(sizeof(Node));
    nw->next = NULL;
    nw->imdb = imdb;
    strcpy(nw->name, name);

    return nw;
}

int isEmpty(Node *head)
{
    return head == NULL;
}

Node *push(Node *head, Node *newNode)
{
    newNode->next = head;
    head = newNode;

    return newNode;
}

Node *pop(Node *head)
{
    if (isEmpty(head))
    {
        printf("Stack is empty\n");
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

    Node *next = head->next;
    //free(head);  // Bunu silmiyorum sorting de kullanılacak
    return next;
}

Node *readFile(const char *filename, Node *head)
{
    FILE *fp = fopen(filename, "r");
    char name[200];
    float imdb;
    do
    {
        fscanf(fp, "%[^,]s", name); // Virgüle kadar tüm stringi al
        fscanf(fp, ",%f\n", &imdb); // diğer satıra kadar olan float degerini sec
        head = push(head, initNode(name, imdb));

    } while (!feof(fp));
    fclose(fp);

    return head;
}

Node *sortStack(Node *inputStack, Node *tmpStack)
{
    while (!isEmpty(inputStack))
    {
        Node *tmp = inputStack;
        inputStack = pop(inputStack);

        while (!isEmpty(tmpStack) && tmpStack->imdb > tmp->imdb)
        {
            inputStack = push(inputStack, initNode(tmpStack->name, tmpStack->imdb)); // Memory leak oluşacak :(
            tmpStack = pop(tmpStack);
        }

        tmpStack = push(tmpStack, tmp);
    }

    return tmpStack;
}

void displayStack(Node *head)
{
    while (!isEmpty(head))
    {
        printf("Name: %s -- IMDB: %.1f\n", head->name, head->imdb);
        head = pop(head);
    }
}

int main(int argc, char const *argv[])
{
    Node *inputStack = NULL, *tmpStack = NULL;
    inputStack = readFile("C:\\Users\\simplex\\Desktop\\work\\works\\2_sinif\\h6\\films.txt", inputStack);
    printf("1. Adimda inputStack\n");
    displayStack(inputStack);
    printf("\n\n");
    tmpStack = sortStack(inputStack, tmpStack);
    printf("3. Adimda inputStack\n");
    displayStack(tmpStack);
    system("PAUSE");
    return 0;
}
