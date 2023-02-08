#ifndef QUEUE_H
#define QUEUE_H

#include "functions.h"

struct MinHeapNode
{
    int v;
    int dist;
};

class Min_Queue
{
public:
    int size;

    int capacity;

    int *pos;

    MinHeapNode **array;

    Min_Queue(int capacity);
    void Heapify(int idx);

    ~Min_Queue();
};

MinHeapNode *New_node(int v, int dist);

void decreaseKey(Min_Queue &Heap, int v, int dist);

MinHeapNode *extractMin(Min_Queue &Heap);

bool isInMinHeap(const Min_Queue &Heap, int v);

int isEmpty(const Min_Queue &Heap);

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b);

#endif // QUEUE_H