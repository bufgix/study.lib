#include <stdlib.h>
#include <stdio.h>

const int STACK_OVERFLOW = -471;
const int EMPTY_STACK = -472;

typedef struct Stack
{
    int maxsize;
    int top;
    int *items;
} Stack;

Stack *newStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->maxsize = capacity;
    stack->top = -1;

    stack->items = (int *)calloc(stack->maxsize, sizeof(int));
    // or
    // stack->items = (int *)malloc(sizeof(int) * stack->maxsize);

    return stack;
}

int sizeStack(Stack *stack)
{
    return stack->top + 1;
}

int isEmptyStack(Stack *stack)
{
    return sizeStack(stack) == 0;
}

int isFullStack(Stack *stack)
{
    return sizeStack(stack) == stack->maxsize;
}

int pushStack(Stack *stack, int data)
{
    if (isFullStack(stack))
    {
        return STACK_OVERFLOW;
    }
    stack->top++;
    stack->items[stack->top] = data;
}

int peekStack(Stack *stack)
{
    if (isEmptyStack(stack))
        return EMPTY_STACK;
    else
        return stack->items[stack->top];
}

int popStack(Stack *stack)
{
    if (isEmptyStack(stack))
        return EMPTY_STACK;
    else
    {
        int pop = stack->items[stack->top];
        stack->top--;
        return pop;
    }
}

int main(int argc, char const *argv[])
{
    Stack *stack = newStack(3);
    pushStack(stack, 10);
    pushStack(stack, 21);
    pushStack(stack, 11);
    int error = 0;
    while (error != EMPTY_STACK)
    {
        error = popStack(stack);
        printf("%d\n", error);
    }
    return 0;
}
