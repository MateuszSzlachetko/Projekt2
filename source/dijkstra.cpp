#include "dijkstra.h"

int Min_distance(int dist[], bool sptSet[], const Graph_m &graph)
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < graph.vertices; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;
    return min_index;
}

void Print_path(std::ostream &stream, int parent[], int j)
{
    // If j is source
    if (parent[j] == -1)
        return;
    Print_path(stream, parent, parent[j]);
    stream << "->" << j;
}

void Print_solution(std::ostream &stream, int dist[], int src, int parent[], const Graph_m &graph)
{
    stream << std::endl
           << "Vertex\t Distance\tPath";
    for (int i = 0; i < graph.vertices; i++)
    {
        stream << std::endl
               << src << " -> " << i << "\t\t " << dist[i] << "\t\t" << src;
        Print_path(stream, parent, i);
    }
    stream << std::endl;
}

float Dijkstra(const Graph_m &graph, int src, Print mode)
{
    float time = 0;
    int *dist = new int[graph.vertices];

    bool *sptSet = new bool[graph.vertices];

    int *parent = new int[graph.vertices];

    for (int i = 0; i < graph.vertices; i++)
    {
        sptSet[i] = false;
        parent[i] = -1;
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    auto start = std::chrono::steady_clock::now();

    for (int count = 0; count < graph.vertices - 1; count++)
    {
        int u = Min_distance(dist, sptSet, graph);

        sptSet[u] = true;

        for (int v = 0; v < graph.vertices; v++)

            if (!sptSet[v] && graph.adjacency_matrix[u][v] && dist[u] + graph.adjacency_matrix[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph.adjacency_matrix[u][v];
            }
    }
    auto end = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    if (mode == Print_on_screen)
    {
        Print_solution(std::cout, dist, src, parent, graph);
    }
    else if (mode == Print_to_file)
    {
        std::ofstream file;
        file.open("../files/result.txt"); // ios:: app
        Print_solution(file, dist, src, parent, graph);
        file.close();
    }

    delete[] parent;
    delete[] dist;
    delete[] sptSet;

    return time;
}

float Dijkstra(const Graph_l &graph, int src, Print mode)
{
    float time = 0;

    int *parent = new int[graph.P];

    int V = graph.P;

    int dist[V];

    Min_Queue Heap(V);

    for (int v = 0; v < V; ++v)
    {
        dist[v] = INT_MAX;
        Heap.array[v] = New_node(v, dist[v]);
        Heap.pos[v] = v;

        parent[v] = -1;
    }

    Heap.array[src] = New_node(src, dist[src]);
    Heap.pos[src] = src;
    dist[src] = 0;
    decreaseKey(Heap, src, dist[src]);

    Heap.size = V;

    auto start = std::chrono::steady_clock::now();
    while (!isEmpty(Heap))
    {

        MinHeapNode *minHeapNode = extractMin(Heap);

        int u = minHeapNode->v;

        Node *pCrawl = graph.head[u];

        while (pCrawl != NULL)
        {
            int v = pCrawl->val;

            if (isInMinHeap(Heap, v) &&
                dist[u] != INT_MAX &&
                pCrawl->cost + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->cost;
                parent[v] = u;

                decreaseKey(Heap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    auto end = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // print the calculated shortest distances
    if (mode == Print_on_screen)
    {
        Print_solution(std::cout, dist, src, parent, graph);
    }
    else if (mode == Print_to_file)
    {
        std::ofstream file;
        file.open("../files/result.txt"); // ios:: app
        Print_solution(file, dist, src, parent, graph);
        file.close();
    }

    delete[] parent;

    return time;
}

void Print_solution(std::ostream &stream, int dist[], int src, int parent[], const Graph_l &graph)
{
    stream << std::endl
           << "Vertex\t Distance\tPath";
    for (int i = 0; i < graph.P; i++)
    {
        stream << std::endl
               << src << " -> " << i << "\t\t " << dist[i] << "\t\t" << src;
        Print_path(stream, parent, i);
    }
    stream << std::endl;
}