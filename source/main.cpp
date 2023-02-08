#include "dijkstra.h"
#include "graph_l.h"

int main()
{
    // Read graph from file
    Graph_l test1("../files/graph.txt");

    test1.Print();

    Dijkstra(test1, 0, Print_on_screen);

    // Read graph from file
    Graph_m test2("../files/graph.txt");

    test2.Print();

    Dijkstra(test2, 0, Print_to_file);

    Graph_l test3(10);
    test3.Create_graph(100);
    Dijkstra(test3, 5, Print_on_screen);

    Dijkstra(test3, 0, Print_on_screen);

    Graph_m test4(10);
    test4.Create_graph(100);
    Dijkstra(test4, 5, Print_on_screen);

    Dijkstra(test4, 0, Print_on_screen);

    int Vertices[] = {10, 50, 100, 500, 1000};
    int Density[] = {25, 50, 75, 100};
    int i = 0, j = 0, k = 0;

    float time = 0;
    Graph_m m_graph10(10);
    Graph_m m_graph50(50);
    Graph_m m_graph100(100);
    Graph_m m_graph500(500);
    Graph_m m_graph1000(1000);
    Graph_m *m_graphs = new Graph_m[5]; // = {graph10, graph50, graph100, graph500, graph1000}
    m_graphs[0] = m_graph10;
    m_graphs[1] = m_graph50;
    m_graphs[2] = m_graph100;
    m_graphs[3] = m_graph500;
    m_graphs[4] = m_graph1000;

    Graph_l l_graph10(10);
    Graph_l l_graph50(50);
    Graph_l l_graph100(100);
    Graph_l l_graph500(500);
    Graph_l l_graph1000(1000);
    Graph_l *l_graphs = new Graph_l[5]; // = {graph10, graph50, graph100, graph500, graph1000}
    l_graphs[0] = l_graph10;
    l_graphs[1] = l_graph50;
    l_graphs[2] = l_graph100;
    l_graphs[3] = l_graph500;
    l_graphs[4] = l_graph1000;

    std::cout << std::endl
              << "Macierz" << std::endl
              << std::endl;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 100; k++)
            {
                m_graphs[i].Create_graph(Density[j]);

                time += Dijkstra(m_graphs[i], 0, No_print);

                m_graphs[i].Clear_graph();
            }

            std::cout << std::endl;
            std::cout << "Ilość wierzchołków: " << Vertices[i];
            std::cout << " Gęstość: " << Density[j] << std::endl;
            std::cout << "Czas " << (time / 100) << " mikrosekund" << std::endl;
            time = 0;
        }
    }

    std::cout << std::endl
              << "Lista" << std::endl
              << std::endl;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 100; k++)
            {
                l_graphs[i].Create_graph(Density[j]);

                time += Dijkstra(l_graphs[i], 0, No_print);

                l_graphs[i].Clear_graph();
            }

            std::cout << std::endl;
            std::cout << "Ilość wierzchołków: " << Vertices[i];
            std::cout << " Gęstość: " << Density[j] << std::endl;
            std::cout << "Czas " << (time / 10) << " mikrosekund" << std::endl;
            time = 0;
        }
    }
}