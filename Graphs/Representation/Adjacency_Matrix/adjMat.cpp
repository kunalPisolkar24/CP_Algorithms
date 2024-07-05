#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

class Graph {
private:
    ll V;
    vvl adj;

public:
    Graph(ll v) : V(v) {
        adj.resize(V, vl(V, 0));
    }

    void addEdge(ll u, ll v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void printAdjMatrix() {
        for (ll i = 0; i < V; ++i) {
            for (ll j = 0; j < V; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);


    cout << "Adjacency Matrix for the graph: \n";
    g.printAdjMatrix();

    return 0;
}