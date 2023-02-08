#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph_m.h"

#include "graph_l.h"

#include "queue.h"

int Min_distance(int dist[], bool sptSet[], const Graph_m &graph);

void Print_path(std::ostream &stream, int parent[], int j);

void Print_solution(std::ostream &stream, int dist[], int src, int parent[], const Graph_m &graph);

void Print_solution(std::ostream &stream, int dist[], int src, int parent[], const Graph_l &graph);

float Dijkstra(const Graph_m &graph, int src, Print mode);

float Dijkstra(const Graph_l &graph, int src, Print mode);

#endif // DIJKSTRA_H