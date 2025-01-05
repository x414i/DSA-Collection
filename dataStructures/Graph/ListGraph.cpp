#include <iostream>
using namespace std;

struct AdjListNode
{
    int dest;
    AdjListNode *next;
};

struct AdjList
{
    AdjListNode *head;
};

struct Graph
{
    int V;
    AdjList *array;
};

AdjListNode *newAdjListNode(int dest)
{
    AdjListNode *newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->next = nullptr;
    return newNode;
}

Graph *createGraph(int V)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->array = new AdjList[V];
    for (int i = 0; i < V; i++)
    {
        graph->array[i].head = nullptr;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->V; v++)
    {
        AdjListNode *temp = graph->array[v].head;
        cout << "Adjacency list of vertex " << v << endl;
        while (temp)
        {
            cout << "-> " << temp->dest;
            temp = temp->next;
        }
        cout << endl;
    }
}

void menu()
{
    cout << "1. Add Edge" << endl;
    cout << "2. Display" << endl;
    cout << "0. Exit" << endl;
}

int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph *graph = createGraph(V);
    int choice;
    do
    {
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int src, dest;
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            addEdge(graph, src, dest);
            break;
        }
        case 2:
        {
            printGraph(graph);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}

