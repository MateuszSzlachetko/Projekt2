#ifndef GRAPH_M_H
#define GRAPH_M_H

#include "functions.h"

class Graph_m
{
private:
    int vertices; // number of vertices
    int **adjacency_matrix;

public:
    Graph_m();
    Graph_m(int number_of_vertices);
    Graph_m(std::string file_name);
    ~Graph_m();

    void Add_edge(int i, int j, int weight);
    void Remove_edge(int i, int j);

    void Create_graph(int density); //  density-percentages 0-100
    void Clear_graph();

    friend int Min_distance(int dist[], bool sptSet[], const Graph_m &graph);
    friend void Print_solution(std::ostream &stream, int dist[], int n, int parent[], const Graph_m &graph);
    friend float Dijkstra(const Graph_m &graph, int src, Print mode);

    void Print();
};

#endif // GRAPH_M_H