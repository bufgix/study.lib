#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int STACK_OVERFLOW = -471;
const int EMPTY_STACK = -472;

const int PARSER_ERROR = -488;

const int INFIX_PRIORITY = -986;
const int STACK_PRIORITY = -985;

const int MAX_SIZE = 50;
const char OPS[] = {'+', '-', '*', '/', '(', ')'};
const size_t OPSLEN = 6;

/* infix: a + b
posfix: a b +
prefix + a b
 */

/* 
    +-----+-----------------------+----------------------+
    | OP  | Infixdeki op ondeligi | stackdaki op oncelig |
    +=====+=======================+======================+
    | (   |                     - |                    - |
    | ^   |                     4 |                    3 |
    | *,/ |                     2 |                    2 |
    | +,- |                     1 |                    1 |
    | (   |                     4 |                    0 |
    +-----+-----------------------+----------------------+

*/

typedef struct Stack_Struct
{
    int top;
    char items[MAX_SIZE];
} Stack;

Stack *newStack();
int sizeStack(Stack *stack);
int isFullStack(Stack *stack);
int isEmptyStack(Stack *stack);
int pushStack(Stack *stack, int data);
int peekStack(Stack *stack);
int popStack(Stack *stack);
int infixToPosfix(const char *infix, Stack *stack);
int isOP(char target);
int getPriority(int op, int PR_TYPE);

Stack *newStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;

    return stack;
}

int main(int argc, char const *argv[])
{
    Stack *stack = newStack();
    infixToPosfix("A*(B+C)/D", stack);
    system("PAUSE");
    return 0;
}

int infixToPosfix(const char *infix, Stack *stack)
{
    char posfix[100] = "";
    int infix_priority = 0;
    int stack_priority = 0;
    int isIter = 1;
    // A*(B+C)/D
    while (*infix != '\0')
    {
        char current = (char)*infix;
        if (isOP(current))
        {
            if (current == '(')
            {
                pushStack(stack, '(');
                infix++;
                continue;
            }
            if (current == ')')
            {
                char op = popStack(stack);
                while (op != '(')
                {
                    if (op != '(')
                        strncat(posfix, &op, 1);
                    op = popStack(stack);
                }
                infix++;
                continue;
            }

            if (getPriority((int)current, INFIX_PRIORITY) > getPriority(peekStack(stack), STACK_PRIORITY))
            {
                pushStack(stack, current);
            }
            else
            {
                char op = popStack(stack);
                strncat(posfix, &op, 1);
            }
        }
        else
        {
            strncat(posfix, &current, 1);
        }
        infix++;
    }
}

/* 
    +-----+-----------------------+----------------------+
    | OP  | Infixdeki op ondeligi | stackdaki op oncelig |
    +=====+=======================+======================+
    | (   |                     - |                    - |
    | ^   |                     4 |                    3 |
    | *,/ |                     2 |                    2 |
    | +,- |                     1 |                    1 |
    | (   |                     4 |                    0 |
    +-----+-----------------------+----------------------+

*/

int getPriority(int op, int PR_TYPE)
{
    if (op == EMPTY_STACK)
    {
        return 0;
    }
    op = (char)op;
    switch (op)
    {
    case '^':
        return PR_TYPE == INFIX_PRIORITY ? 4 : 3;

    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
        break;
    }
}

int isOP(char target)
{
    for (int i = 0; i < OPSLEN; i++)
    {
        if (OPS[i] == target)
            return 1;
    }
    return 0;
}

int popStack(Stack *stack)
{
    if (isEmptyStack(stack))
        return EMPTY_STACK;
    int pop = stack->items[stack->top];
    stack->top--;

    return pop;
}

int peekStack(Stack *stack)
{
    if (isEmptyStack(stack))
        return EMPTY_STACK;
    return stack->items[stack->top];
}

int pushStack(Stack *stack, int data)
{
    if (isFullStack(stack))
        return STACK_OVERFLOW;
    stack->top++;
    stack->items[stack->top] = data;
    return data;
}

int sizeStack(Stack *stack)
{
    return stack->top + 1;
}

int isFullStack(Stack *stack)
{
    return sizeStack(stack) == MAX_SIZE;
}

int isEmptyStack(Stack *stack)
{
    return sizeStack(stack) == 0;
}
