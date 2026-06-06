#include "Stack.h"

#define STACK_SIZE 5
int queue_table[STACK_SIZE] = { 0 };

int head = 0;
int tail = 0;
int count = 0;

int isQueueEmpty(void)
{
    return (count == 0) ? 1 : 0;
}

int isQueueFull(void)
{
    return (count == STACK_SIZE) ? 1 : 0;
}

void Push(int val)
{
    if (!isQueueFull())
    {
        queue_table[tail] = val;
        tail = (tail + 1) % STACK_SIZE;
        count++;
    }
}

int Pop(void)
{
    if (!isQueueEmpty())
    {
        int val = queue_table[head];
        head = (head + 1) % STACK_SIZE;
        count--;
        return val;
    }
    return 0;
}

int Top(void)
{
    if (!isQueueEmpty())
    {
        return queue_table[head];
    }
    return 0;
}