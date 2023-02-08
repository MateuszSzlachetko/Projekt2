#include "graph_l.h"

Node *Graph_l::getAdjListNode(int value, int weight, Node *head)
{
    Node *New_node = new Node;
    New_node->val = value;
    New_node->cost = weight;

    New_node->next = head;

    return New_node;
}

Graph_l::Graph_l(std::string file_name)
{
    std::ifstream file;

    file.open(file_name);
    int edges, start, number_of_vertices;
    file >> edges;
    file >> number_of_vertices;
    file >> start;

    N = number_of_vertices;
    P = N;
    head = new Node *[N]();

    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++)
    {
        head[i] = nullptr;
    }
    int src = 0;
    int dest = 0;
    int weight = 0;

    for (int i = 0; i < edges; i++) // while (!file.eof())
    {
        file >> src;
        file >> dest;
        file >> weight;
        // insert at the beginning
        Node *newNode = getAdjListNode(dest, weight, head[src]);

        // point head pointer to the new node
        head[src] = newNode;

        newNode = getAdjListNode(src, weight, head[dest]);

        // change head pointer to point to the new node
        head[dest] = newNode;
    }

    file.close();
}

Graph_l::Graph_l()
{
    this->N = 1;
    head = new Node *[N]();
    P = N;

    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++)
    {
        head[i] = nullptr;
    }
}

Graph_l::Graph_l(int N)
{
    head = new Node *[N]();
    this->N = N;
    P = N;

    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++)
    {
        head[i] = nullptr;
    }
}

void Graph_l::Create_graph(int density)
{
    int edges;
    float d;

    d = float(density) / 100;

    edges = int((d * (N * (N - 1))) / 2);

    int i = 0, a = 0, b = 0, weight = 0, k = 0;

    if (d != 1)
    {
        while (i < edges)
        {
            while ((a == b) || (Find_edge(head[a], b)))
            {
                a = Random_int(0, N - 1);
                b = Random_int(0, N - 1);
            }

            weight = Random_int(3, 10);

            Node *newNode = getAdjListNode(b, weight, head[a]);

            // point head pointer to the new node
            head[a] = newNode;

            newNode = getAdjListNode(a, weight, head[b]);

            // change head pointer to point to the new node
            head[b] = newNode;

            a = 0;
            b = 0;
            i++;
        }
    }
    else
    {
        for (int j = 0; j < N; j++)
        {
            k = j + 1;
            for (k; k < N; k++)
            {
                weight = Random_int(3, 10);
                Node *newNode = getAdjListNode(k, weight, head[j]);

                // point head pointer to the new node
                head[j] = newNode;

                newNode = getAdjListNode(j, weight, head[k]);

                // change head pointer to point to the new node
                head[k] = newNode;
            }
        }
    }
}

Graph_l::~Graph_l()
{
    for (int i = 0; i < N; i++)
    {
        delete[] head[i];
    }
    delete[] head;
}

bool Find_edge(Node *head, int value)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->val == value)
            return true;
        p = p->next;
    }
    return false;
}

void Graph_l::Print()
{
    Node *ptr = nullptr;
    for (int i = 0; i < N; i++)
    {
        Node *ptr = (head[i]);
        std::cout << "N: " << i;
        while (ptr != nullptr)
        {
            std::cout << " <- " << ptr->val << " "
                      << "[w:" << ptr->cost << "] ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
}

void Graph_l::Clear_graph()
{
    for (int i = 0; i < N; i++)
    {
        delete[] head[i];
    }

    for (int i = 0; i < N; i++)
    {
        head[i] = nullptr;
    }
}