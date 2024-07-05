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

    vl shortestPath(ll start, ll end) {
        vl dist(V, numeric_limits<ll>::max());
        vl prev(V, -1);
        queue<ll> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            ll u = q.front();
            q.pop();

            if (u == end) break;

            for (ll v : adj[u]) {
                if (dist[v] == numeric_limits<ll>::max()) {
                    dist[v] = dist[u] + 1;
                    prev[v] = u;
                    q.push(v);
                }
            }
        }

        vl path;
        for (ll v = end; v != -1; v = prev[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 7);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    ll start = 0, end = 6;
    vl path = g.shortestPath(start, end);

    cout << "Shortest path from " << start << " to " << end << ": ";
    for (ll v : path) 
        cout << v << " ";
    
    cout << endl;

    cout << "Length of the path: " << path.size() - 1 << endl;

    return 0;
}