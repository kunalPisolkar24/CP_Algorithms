#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<vector<long long>> vvl;
class Graph {
private:
    ll V;
    vvl adj;
public:
    Graph(ll v): V(v) {
        adj.resize(V);
    }

    void addEdge(ll u, ll v) {
        adj[u].push_back(v);
    }

   void printAdjList() {
        for (int v = 0; v < V; ++v) {
            cout << v << " -> ";
            if (adj[v].empty()) {
                cout << "[]";
            } else {
                cout << "[ ";
                for (int i = 0; i < adj[v].size(); ++i) {
                    cout << adj[v][i];
                    if (i < adj[v].size() - 1) cout << ", ";
                }
                cout << " ]";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Adjacency List for graph : \n";
    g.printAdjList();

    return 0;
}
