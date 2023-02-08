#include "graph_m.h"

Graph_m::Graph_m()
{
    int number_of_vertices = 1;
    this->vertices = number_of_vertices;

    adjacency_matrix = new int *[number_of_vertices];

    for (int i = 0; i < number_of_vertices; ++i)
    {
        adjacency_matrix[i] = new int[number_of_vertices];

        for (int j = 0; j < number_of_vertices; ++j)
        {
            adjacency_matrix[i][j] = 0; // init matrix with 0
        }
    }
}

Graph_m::Graph_m(int number_of_vertices)
{
    this->vertices = number_of_vertices;

    adjacency_matrix = new int *[number_of_vertices];

    for (int i = 0; i < number_of_vertices; ++i)
    {
        adjacency_matrix[i] = new int[number_of_vertices];

        for (int j = 0; j < number_of_vertices; ++j)
        {
            adjacency_matrix[i][j] = 0; // init matrix with 0
        }
    }
}

Graph_m::Graph_m(std::string file_name)
{
    std::ifstream file;

    file.open(file_name);
    int edges, start, number_of_vertices;
    file >> edges;
    file >> number_of_vertices;
    file >> start;

    this->vertices = number_of_vertices;

    adjacency_matrix = new int *[number_of_vertices];

    for (int i = 0; i < number_of_vertices; ++i)
    {
        adjacency_matrix[i] = new int[number_of_vertices];

        for (int j = 0; j < number_of_vertices; ++j)
        {
            adjacency_matrix[i][j] = 0; // init matrix with 0
        }
    }

    int i, j, weight;

    while (!file.eof())
    {
        file >> i;
        file >> j;
        file >> weight;

        (*this).Add_edge(i, j, weight);
    }

    file.close();
}

void Graph_m::Add_edge(int i, int j, int weight)
{
    adjacency_matrix[i][j] = weight;
    adjacency_matrix[j][i] = weight;
}

void Graph_m::Remove_edge(int i, int j)
{
    adjacency_matrix[i][j] = 0;
    adjacency_matrix[j][i] = 0;
}

void Graph_m::Create_graph(int density) // d=2e/(v(v-1))
{
    int edges;
    float d;

    d = float(density) / 100;

    edges = int((d * (vertices * (vertices - 1))) / 2);

    /// Mamy naszą ilość krawędzi
    int i = 0, a = 0, b = 0, weight = 0, k = 0;

    if (d != 1)
    {
        while (i < edges) // wykonuj dopóki nie stworzymy wszystkich krawędzi
        {
            while (a == b || adjacency_matrix[a][b] != 0) // losuj takie wierzchołki, które nie są sobie równe i nie są już połączone
            {
                a = Random_int(0, vertices - 1);
                b = Random_int(0, vertices - 1);
            }

            weight = Random_int(3, 10);

            (*this).Add_edge(a, b, weight);

            a = 0;
            b = 0;
            i++;
        }
    }
    else
    {
        for (int j = 0; j < vertices; j++)
        {
            k = j + 1;
            for (k; k < vertices; k++)
            {
                weight = Random_int(3, 10);
                (*this).Add_edge(j, k, weight);
            }
        }
    }
}

void Graph_m::Clear_graph()
{
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            adjacency_matrix[i][j] = 0; // fill matrix with 0
        }
    }
}

void Graph_m::Print()
{
    std::cout << std::endl;
    for (int i = 0; i < vertices; ++i)
    {

        for (int j = 0; j < vertices; ++j)
        {
            std::cout << " " << std::setw(3) << adjacency_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Graph_m::~Graph_m()
{
    for (int i = 0; i < vertices; i++)
        delete[] adjacency_matrix[i];

    delete[] adjacency_matrix;
}