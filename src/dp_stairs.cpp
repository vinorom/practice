#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 1000000;

ll count_ways(int n)
{
    static ll cache[MAXN];

    if (n < 0) return 0;
    if (n == 0) return 1;
    if (cache[n] > 0) return cache[n];
    cache[n] = count_ways(n - 1) + count_ways(n - 2) + count_ways(n - 3);
    return cache[n];
}

int main()
{
    for (int i = 0; i < 40; ++i) cout << "N=" << i << ": " << count_ways(i) << '\n';
    return 0;
}