#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<unordered_map>
using namespace std;

class Graph_adj_list{
    public:
        void addEdge(int u, int v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        void removeEdge(int u, int v){
           auto it_u = find(graph[u].begin(), graph[u].end(), v);
            if (it_u != graph[u].end()) {
                graph[u].erase(it_u);
            }
           auto it_v = find(graph[v].begin(), graph[v].end(), u);
            if (it_v != graph[v].end()) {
                graph[v].erase(it_v);
            }
        }

        vector<int> getNeighbours(int u){
            if (graph.find(u) != graph.end()){
                return graph[u];
            }
            return {};
        }

        void printGraph(){
            for (const auto& pair : graph){
                cout << pair.first << " : ";
                for (int v : pair.second){
                    cout << v << " ";
                }
                cout << endl;
            }
        }

    private:
        unordered_map<int,vector<int>>graph;

};
   
int main()
{
    Graph_adj_list g;
    int u, v, choice;
    while (true){
        cout << "\n Graph Menu:" << endl;
        cout << "1. Add Edge" << endl;
        cout << "2. Remove Edge" << endl;
        cout << "3. Get neighbours" << endl;
        cout << "4. Print graph" << endl;
        cout << "0. Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1: cout << "Enter values of u & v : " ;
                cin >> u >> v;
                g.addEdge(u,v);            
            break;
        case 2: cout << "Enter values of u & v : " ;
                cin >> u >> v;
                g.removeEdge(u,v);
            break;
        case 3: cout << "Enter the vertex: " ;
                cin >> u;
                cout << "Neighbours of "<< u << " : ";
                for( auto neighbour : g.getNeighbours(u)){
                     cout << neighbour << " ";
                }
                cout << endl;
            break;
        case 4: cout << "Graph:\n";
                g.printGraph();
            break;
        case 0: cout << "Exiting...";
                exit(0);
            break;
        default: cout << "Invalid choice. Please try again";
            break;
        }
    }
    return 0;
}