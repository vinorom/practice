#include <bits/stdc++.h>

using namespace std;

using adj_list_t = vector<int>;
using graph = vector<adj_list_t>;

void visit(int n) { cout << n << ' '; }

void bfs(const graph& g, int src)
{
    vector<bool> visited(g.size());

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();

        visited[v] = true;

        for (int i = 0; i < g[v].size(); ++i)
        {
            int u = g[v][i];
            if (!visited[u]) q.push(u);
        }

        visit(v);
    }

    cout << '\n';
}

int main()
{
    graph g = {{1, 2}, {2}, {0, 3}, {3}};
    bfs(g, 2);
    return 0;
}