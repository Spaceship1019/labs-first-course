#ifndef __QUEUE_H__
#define __QUEUE_H__
#define MAX 1000
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
    struct QueueNode* prev;
} QueueNode;

typedef struct Queue {
    struct QueueNode* front;
    struct QueueNode* back;
    int size;
} Queue;

Queue* Make();
int Empty(Queue* q);
Queue* Add(Queue* q, int num);
void Print(Queue* q);
int Back(Queue* q);
int Front(Queue* q);
Queue* Pop(Queue* q);
void PrintReverse(Queue* q);
Queue* Result(Queue* q);
#endif 
