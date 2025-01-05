#include <iostream>
#define MAX_VERTICES 100 // Maximum number of vertices in the graph <#define is macro>

using namespace std;

void addVertex(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) 
{
    for (int i = 0; i < numVertices; i++) 
    {
        adjMatrix[numVertices][i] = 0;
        adjMatrix[i][numVertices] = 0;
    }
}
void addEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int u, int v) 
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; 
}

void removeEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int u, int v) 
{
    adjMatrix[u][v] = 0;
    adjMatrix[v][u] = 0; 
}

void display(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) 
{
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void menu() 
{
    cout << "1. add Vertex " << endl;
    cout << "2. Add Edge" << endl;
    cout << "3. Remove Edge" << endl;
    cout << "4. Display" << endl;
    cout << "0. Exit" << endl;
}

int main() 
{
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int numVertices;
    cout << "Enter number of vertices: ";
    cin >> numVertices;
    int choice;
    do 
    {
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) 
        {
            case 1: 
            {
                addVertex(adjMatrix, numVertices);
                numVertices++;
                break;
            }
            case 2: 
            {
                int u, v;
                cout << "Enter vertices to add edge: ";
                cin >> u >> v;
                addEdge(adjMatrix, u, v);
                break;
            }
            case 3: 
            {
                int u, v;
                cout << "Enter vertices to remove edge: ";
                cin >> u >> v;
                removeEdge(adjMatrix, u, v);
                break;
            }
            case 4: 
            {
                display(adjMatrix, numVertices);
                break;
            }
            case 0: 
            {
                cout << "Exiting..." << endl;
                break;
            }
            default: 
            {
                cout << "Invalid choice" << endl;
            }
        }
    } while (choice != 0);

    return 0;
}