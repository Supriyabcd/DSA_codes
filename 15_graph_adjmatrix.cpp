#include <iostream>
#include <vector>
using namespace std;

class GraphAdjMatrix {
public:
    GraphAdjMatrix(int vertices) {
        this->vertices = vertices;
        // Initialize the adjacency matrix with 0s
        matrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            matrix[u][v] = 1;
            matrix[v][u] = 1; // Undirected graph
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    void removeEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            matrix[u][v] = 0;
            matrix[v][u] = 0; // Undirected graph
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    vector<int> getNeighbours(int u) {
        vector<int> neighbours;
        if (u >= 0 && u < vertices) {
            for (int v = 0; v < vertices; ++v) {
                if (matrix[u][v] == 1) {
                    neighbours.push_back(v);
                }
            }
        } else {
            cout << "Invalid vertex!" << endl;
        }
        return neighbours;
    }

    void printGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int vertices;
    vector<vector<int>> matrix;
};

int main() {
    int vertices, choice, u, v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    GraphAdjMatrix g(vertices);

    while (true) {
        cout << "\nGraph Menu:" << endl;
        cout << "1. Add Edge" << endl;
        cout << "2. Remove Edge" << endl;
        cout << "3. Get Neighbours" << endl;
        cout << "4. Print Graph" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter values of u & v: ";
            cin >> u >> v;
            g.addEdge(u, v);
            break;
        case 2:
            cout << "Enter values of u & v: ";
            cin >> u >> v;
            g.removeEdge(u, v);
            break;
        case 3:
            cout << "Enter the vertex: ";
            cin >> u;
            cout << "Neighbours of " << u << " : ";
            for (int neighbour : g.getNeighbours(u)) {
                cout << neighbour << " ";
            }
            cout << endl;
            break;
        case 4:
            g.printGraph();
            break;
        case 0:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
