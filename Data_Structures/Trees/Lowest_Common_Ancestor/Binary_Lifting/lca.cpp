#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

class LCA {
private:
    vvl graph;
    vvl up;
    vl tin, tout, depth;
    ll n, l, timer;

    void dfs(ll v, ll p, ll d) {
        tin[v] = ++timer;
        up[v][0] = p;
        depth[v] = d;
        for (ll i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];
        for (auto u : graph[v]) {
            if (u != p)
                dfs(u, v, d + 1);
        }
        tout[v] = ++timer;
    }

    bool is_ancestor(ll u, ll v) const {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

public:
    LCA(ll size) : n(size), graph(size), tin(size), tout(size), depth(size) {
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vl(l + 1));
    }

    void add_edge(ll u, ll v) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    void preprocess(ll root) {
        if (root >= 0 && root < n) {
            dfs(root, root, 0);
        }
    }

    ll findLCA(ll u, ll v) const {
        if (u < 0 || u >= n || v < 0 || v >= n) return -1; // Invalid input
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (ll i = l; i >= 0; --i)
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }

    ll find_distance(ll u, ll v) const {
        if (u < 0 || u >= n || v < 0 || v >= n) return -1; // Invalid input
        ll lca = findLCA(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }
};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    ll n, q;
    cout << "Enter the number of nodes and queries: ";
    cin >> n >> q;

    if (n <= 0 || q < 0) {
        cout << "Invalid input. Number of nodes should be positive and queries non-negative.\n";
        return 1;
    }

    LCA lca(n);

    cout << "Enter " << n-1 << " edges (u v):\n";
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        lca.add_edge(u, v);
    }

    lca.preprocess(0);  // Assuming 0 is the root

    cout << "Enter " << q << " queries (type u v):\n";
    cout << "Type 1: Find LCA\n";
    cout << "Type 2: Find distance\n";

    while (q--) {
        ll type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            ll result = lca.findLCA(u, v);
            if (result != -1)
                cout << "LCA of " << u << " and " << v << " is: " << result << '\n';
            else
                cout << "Invalid input for LCA query.\n";
        } else if (type == 2) {
            ll result = lca.find_distance(u, v);
            if (result != -1)
                cout << "Distance between " << u << " and " << v << " is: " << result << '\n';
            else
                cout << "Invalid input for distance query.\n";
        } else {
            cout << "Invalid query type. Use 1 for LCA or 2 for distance.\n";
        }
    }

    return 0;
}
