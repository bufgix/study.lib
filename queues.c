#include <stdlib.h>
#include <stdio.h>

#define MAX_QUE_SIZE 10

typedef struct _Que
{
    int front, rear, size;
    int items[MAX_QUE_SIZE];
} Queue;

Queue *newQueue()
{
    Queue *que = (Queue *)malloc(sizeof(Queue));
    que->size = 0;
    que->front = 0;
    que->rear = -1;

    return que;
}

int isFull(Queue *que)
{
    return que->size == MAX_QUE_SIZE;
}

int isEmpty(Queue *que)
{
    return que->size == 0;
}

void enQueue(Queue *que)
{
    
}

int main(int argc, char const *argv[])
{
    Queue *que = newQueue();

    system("PAUSE");
    return 0;
}
