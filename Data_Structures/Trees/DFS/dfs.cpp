#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

class Tree {
private:
    ll V;
    vvl adj;

public:
    Tree(ll v) : V(v) {
        adj.resize(V);
    }

    void addEdge(ll u, ll v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(ll v, ll parent = -1) {
        cout << v << " ";

        for(auto child: adj[v]) {
            if(child != parent) dfs(child, v);
        }
    }
};

int main() {
    Tree tree(7);
    
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);
    tree.addEdge(2, 6);

    std::cout << "DFS traversal starting from root (vertex 0): ";
    tree.dfs(0);
    std::cout << std::endl;

    return 0;
}