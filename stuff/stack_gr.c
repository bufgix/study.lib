#include <stdlib.h>
#include <stdio.h>

const int MAX_SIZE = 100;

typedef struct Stack
{
    int top;
    int items[MAX_SIZE];
} Stack;

Stack *newStack()
{
    Stack *newSt = (Stack *)malloc(sizeof(Stack));
    newSt->top = -1;

    return newSt;
}

int sizeStack(Stack *st)
{
    return st->top + 1;
}

int isEmpty(Stack *st)
{
    return sizeStack(st) == 0;
}

int isFull(Stack *st)
{
    return sizeStack(st) == MAX_SIZE;
}

void pushStack(Stack *st, int newData)
{
    if (isFull(st) == 1)
    {
        exit(EXIT_FAILURE);
    }
    st->top++;
    st->items[st->top] = newData;
}

int peekStack(Stack *st)
{
    if (isEmpty(st))
    {
        exit(EXIT_FAILURE);
    }
    return st->items[st->top];
}

int popStack(Stack *st)
{
    if (isEmpty(st))
    {
        exit(EXIT_FAILURE);
    }
    int pop = st->items[st->top];
    st->top--;
    return pop;
}

int main(int argc, char const *argv[])
{
    Stack *myStack = newStack();
    pushStack(myStack, 12);
    pushStack(myStack, 31);
    int peeked = peekStack(myStack);
    int poped = popStack(myStack);
    system("PAUSE");
    return 0;
}
