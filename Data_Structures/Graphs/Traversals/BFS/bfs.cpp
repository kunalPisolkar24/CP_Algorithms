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

    void BFS(ll s) {
        vector<bool> visited(V, false);
        queue<ll> queue;

        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop();

            for (ll adjacent : adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push(adjacent);
                }
            }
        }
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

    cout << "Following is Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2);
    cout << endl;
    return 0;
}