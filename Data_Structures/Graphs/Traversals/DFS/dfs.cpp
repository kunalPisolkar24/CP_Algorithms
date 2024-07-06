#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

class Graph {
private:
    ll V;
    vector<vector<ll>> adj;

public:
    Graph(ll v) : V(v) {
        adj.resize(V);
    }

    void addEdge(ll u, ll v) {
        adj[u].push_back(v);
    }

    void DFSIterative(ll s) {
        vector<bool> visited(V, false);
        stack<ll> stack;

        stack.push(s);

        while (!stack.empty()) {
            s = stack.top();
            stack.pop();

            if (!visited[s]) {
                cout << s << " ";
                visited[s] = true;
            }

            for (auto i: adj[s]) {
                if (!visited[i]) {
                    stack.push(i);
                }
            }
        }
    }

    void DFSRecursiveUtil(ll v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (ll i : adj[v]) {
            if (!visited[i]) {
                DFSRecursiveUtil(i, visited);
            }
        }
    }

    void DFSRecursive(ll s) {
        vector<bool> visited(V, false);
        DFSRecursiveUtil(s, visited);
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Iterative DFS starting from vertex 2: ";
    g.DFSIterative(2);
    cout << endl;

    cout << "Recursive DFS starting from vertex 2: ";
    g.DFSRecursive(2);
    cout << endl;

    return 0;
}