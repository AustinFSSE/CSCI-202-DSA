#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// edges[i] = {u,v}
// adj[u] holds list of edge‐indices incident on u
vector<pair<int,int>> edges;
vector<vector<int>>   adj;
vector<bool>          usedEdge;

// DFS to count reachable vertices from u via unused edges
int dfsCount(int u, vector<bool>& vis) {
    vis[u] = true;
    int cnt = 1;
    for (int ei : adj[u]) {
        if (usedEdge[ei]) continue;
        int v = edges[ei].first ^ edges[ei].second ^ u;
        if (!vis[v]) cnt += dfsCount(v, vis);
    }
    return cnt;
}

// Is edge ei=(u,*) a bridge in the remaining‐edges subgraph?
bool isBridge(int u, int ei) {
    vector<bool> vis(adj.size(), false);
    int before = dfsCount(u, vis);

    usedEdge[ei] = true;
    fill(vis.begin(), vis.end(), false);
    int after  = dfsCount(u, vis);
    usedEdge[ei] = false;

    return (after < before);
}

// Fleury’s walk: recursively traverse safely
void fleury(int u, vector<int>& path) {
    for (int ei : adj[u]) {
        if (usedEdge[ei]) continue;
        int v = edges[ei].first ^ edges[ei].second ^ u;

        // only‐edge check
        bool onlyEdge = true;
        for (int ej : adj[u]) {
            if (!usedEdge[ej] && ej != ei) {
                onlyEdge = false;
                break;
            }
        }
        if (!onlyEdge && isBridge(u, ei))
            continue;

        usedEdge[ei] = true;
        fleury(v, path);
    }
    path.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- SAMPLE GRAPH DEFINITION ---
    // 3-cycle (Eulerian circuit): 0–1–2–0
    int V = 3;
    vector<pair<int,int>> edges_input = {
        {0,1},
        {1,2},
        {2,0}
    };
    int E = edges_input.size();

    // Build data structures
    adj .assign(V, {});
    usedEdge.assign(E, false);
    edges.clear();

    for (int i = 0; i < E; i++) {
        auto [u,v] = edges_input[i];
        edges.emplace_back(u, v);
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    // find vertices of odd degree
    vector<int> odd;
    for (int u = 0; u < V; u++)
        if (adj[u].size() % 2) odd.push_back(u);

    if (odd.size() != 0 && odd.size() != 2) {
        cout << "Graph is not Eulerian (" << odd.size()
             << " odd‑degree vertices)" << endl;
        return 0;
    }

    int start = odd.empty() ? 0 : odd[0];
    vector<int> path;
    fleury(start, path);
    reverse(path.begin(), path.end());

    cout << (odd.size() == 2 ? "Eulerian trail:" : "Eulerian circuit:")
         << endl;
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i] << (i + 1 < (int)path.size() ? " -> " : "\n");
    }
    return 0;
}
