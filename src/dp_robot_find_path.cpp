#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

bool is_busy[MAXN][MAXN];

bool is_free(int x, int y)
{
    if (x < 0 || x >= MAXN || y < 0 || y >= MAXN) return false;
    return !is_busy[x][y];
}

struct point
{
    int x;
    int y;
};

struct hash_pair
{
    size_t operator()(const pair<int, int>& p) const { hash<int> h; return h(p.first) * h(p.second); }
};

bool find_path(int x, int y, deque<point>& path, unordered_set<pair<int, int>, hash_pair>& visited)
{
    if (visited.count(make_pair(x, y)) > 0) return false;

    if (!is_free(x, y)) return false;

    path.push_front({x, y});

    bool success = x == 0 && y == 0;
    if (!success && x > 0) success = find_path(x - 1, y, path, visited);
    if (!success && y > 0) success = find_path(x, y - 1, path, visited);

    if (!success) path.pop_front();

    visited.insert(make_pair(x, y));

    return success;
}

void solve(int x, int y)
{
    hash_pair h;
    unordered_set<pair<int, int>, hash_pair> visited(100, h);
    deque<point> path;
    auto res = find_path(x, y, path, visited);
    cout << "X=" << x << " Y=" << y << ": ";
    if (res)
    {
        for (auto p: path) cout << "(" << p.x << "," << p.y << ") -> ";
        cout << '\n';
    }
    else
        cout << "NO PATH\n";
}

int main()
{
    solve(4, 5);

    is_busy[1][5] = is_busy[2][4] = is_busy[3][3] = true;
    solve(4, 5);

    is_busy[3][0] = is_busy[2][1] = is_busy[1][2] = true;
    solve(4, 5);
    return 0;
}
