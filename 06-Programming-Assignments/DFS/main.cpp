#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this for directed graphs
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from node " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
    void displayGraph() {
        cout << "Adjacency Matrix Representation of the Graph:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (find(adj[i].begin(), adj[i].end(), j) != adj[i].end())
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
    void displayConnections() {
        vector<vector<int>> adjMatrix = {
            {0, 1, 1, 0, 0},
            {1, 0, 0, 1, 0},
            {1, 0, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 1, 1, 0}
        };
        int V = adjMatrix.size();
    
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " is connected to: ";
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.DFS(0);
    g.displayGraph();
    g.displayConnections();
    return 0;
}
