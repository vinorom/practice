#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 1000;

ll count_paths(int n, int m)
{
    static ll dp[MAXN][MAXN];
    if (n < 1 || m < 1) return 0;
    if (n == 1 && m == 1) return 0;
    if (n == 1 || m == 1) return 1;
    if (dp[n][m] > 0) return dp[n][m];
    dp[n][m] = count_paths(n - 1, m) + count_paths(n, m - 1);
    return dp[n][m];
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 15; ++j)
            cout << '[' << i << ',' << j << "]: " << count_paths(i, j) << '\n';
    }
    return 0;
}
