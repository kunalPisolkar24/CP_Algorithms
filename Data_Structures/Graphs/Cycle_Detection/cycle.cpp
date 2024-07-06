#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

class Graph {
private:
    ll V;
    vvl adj;

public:
    Graph(ll v) : V(v) {
        adj.resize(V);
    }

    void addEdge(ll u, ll v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCyclicUtil(ll v, vector<bool>& visited, ll parent) {
        visited[v] = true;

        for (ll neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, v))
                    return true;
            }
            else if (neighbor != parent)
                return true;
        }
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false);

        for (ll i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    cout << "Graph 1: " << (g1.isCyclic() ? "Contains cycle" : "No cycle detected") << endl;

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    cout << "Graph 2: " << (g2.isCyclic() ? "Contains cycle" : "No cycle detected") << endl;

    return 0;
}