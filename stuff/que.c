#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

const int MAX_QUE_SIZE = 10;

typedef struct _Que
{
    int rear, front, size;
    int items[MAX_QUE_SIZE];
} Queue;
 
Queue *newQueue()
{
    Queue *que = (Queue *)malloc(sizeof(Queue));

    que->front = 0;
    que->size = 0;
    que->rear = -1;

    return que;
}

int isEmpty(Queue *que)
{
    return que->size == 0;
}

int isFull(Queue *que)
{
    return que->size == MAX_QUE_SIZE;
}

int enQueue(Queue *que, int item)
{
    if (isFull(que))
        return INT_MAX;
    que->rear = (que->rear + 1) % MAX_QUE_SIZE;
    que->items[que->rear] = item;
    que->size++;

    return item;
}

int deQueue(Queue *que)
{
    if (isEmpty(que))
        return INT_MIN;
    int item = que->items[que->front];
    que->front = (que->front + 1) % MAX_QUE_SIZE;
    que->size--;

    return item;
}

int main(int argc, char const *argv[])
{
    Queue *que = newQueue();
    enQueue(que, 12);
    enQueue(que, 33);
    enQueue(que, 55);

    int a = deQueue(que);
    a = deQueue(que);
    system("PAUSE");
    return 0;
}
