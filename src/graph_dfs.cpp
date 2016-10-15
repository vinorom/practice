#include <bits/stdc++.h>

using namespace std;

using adj_list_t = vector<int>;
using graph = vector<adj_list_t>;

void visit(int n) { cout << n << ' '; }

void dfs(const graph& g, int v, vector<bool>& visited)
{
    if (visited[v]) return;
    visited[v] = true;
    for (int i = 0; i < g[v].size(); ++i) dfs(g, g[v][i], visited);
    visit(v);
}

void dfs(const graph& g, int src)
{
    vector<bool> visited(g.size());
    dfs(g, src, visited);
    cout << '\n';
}

int main()
{
    graph g = {{1, 2}, {2}, {0, 3}, {3}};
    dfs(g, 2);
    return 0;
}