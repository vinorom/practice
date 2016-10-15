#include <bits/stdc++.h>

using namespace std;

int coins[] = {1, 2, 3, 4, 5};

using ll=long long;

long long count_ways(int n)
{
    long long dp[n+1];
    fill(dp, dp + n + 1, 0);
    dp[0] = 1;

    for (auto c: coins)
    {
        for (int i = c; i <= n; ++i) dp[i] += dp[i - c];
    }

    return dp[n];
}

int main()
{
    for (int i = 0; i < 50; ++i) cout << "N=" << i << ": " << count_ways(i) << '\n';
    return 0;
}