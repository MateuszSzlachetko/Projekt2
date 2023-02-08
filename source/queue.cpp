#include "queue.h"

Min_Queue::Min_Queue(int capacity)
{
    this->pos = new int[capacity];
    this->size = 0;
    this->capacity = capacity;
    this->array = new MinHeapNode *[capacity]();
}

Min_Queue::~Min_Queue()
{
    delete[] pos;

    delete[] array;
}

bool isInMinHeap(const Min_Queue &Heap, int v)
{
    if (Heap.pos[v] < Heap.size)
        return true;
    return false;
}

int isEmpty(const Min_Queue &Heap)
{
    return Heap.size == 0;
}

MinHeapNode *New_node(int v, int dist)
{
    MinHeapNode *New_node = new MinHeapNode;
    New_node->v = v;
    New_node->dist = dist;
    return New_node;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void Min_Queue::Heapify(int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < this->size && this->array[left]->dist < this->array[smallest]->dist)
        smallest = left;

    if (right < this->size && this->array[right]->dist < this->array[smallest]->dist)
        smallest = right;

    if (smallest != idx)
    {
        // The nodes to be swapped in min heap
        MinHeapNode *smallestNode =
            this->array[smallest];
        MinHeapNode *idxNode =
            this->array[idx];

        // Swap positions
        this->pos[smallestNode->v] = idx;
        this->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&this->array[smallest], &this->array[idx]);

        Heapify(smallest);
    }
}

MinHeapNode *extractMin(Min_Queue &Heap)
{
    if (isEmpty(Heap))
        return NULL;

    // Store the root node
    MinHeapNode *root = Heap.array[0];

    // Replace root node with last node
    MinHeapNode *lastNode = Heap.array[Heap.size - 1];
    Heap.array[0] = lastNode;

    // Update position of last node
    Heap.pos[root->v] = Heap.size - 1;
    Heap.pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    Heap.size = Heap.size - 1;
    Heap.Heapify(0);

    return root;
}

void decreaseKey(Min_Queue &Heap, int v, int dist)
{
    int i = Heap.pos[v];

    Heap.array[i]->dist = dist;

    while (i && Heap.array[i]->dist < Heap.array[(i - 1) / 2]->dist)
    {

        Heap.pos[Heap.array[i]->v] = (i - 1) / 2;
        Heap.pos[Heap.array[(i - 1) / 2]->v] = i;

        swapMinHeapNode(&Heap.array[i], &Heap.array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}
