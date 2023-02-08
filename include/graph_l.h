#ifndef GRAPH_L_H
#define GRAPH_L_H

#include "functions.h"

struct Node
{
    int val, cost;
    Node *next;
};

class Graph_l
{
    Node *getAdjListNode(int value, int weight, Node *head);

    int N; //  Vertices

public:
    Node **head;
    int P;

    Graph_l();
    Graph_l(int N);
    Graph_l(std::string file_name);

    void Create_graph(int density);

    ~Graph_l();

    void Clear_graph();

    void Print();
};

bool Find_edge(Node *head, int value);

#endif // GRAPH_L_H