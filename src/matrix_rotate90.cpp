#include <bits/stdc++.h>

using namespace std;

/**
 *     x x x x
 *     x x x x
 * M = x x x x
 *     x x x x
 */
template <int n> void rotate(int m[n][n])
{
    for (int i = 0; i < n / 2 + (n & 1); ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            int a = m[i][j];
            m[i][j] = m[n-1-j][i];
            m[n-1-j][i] = m[n-1-i][n-1-j];
            m[n-1-i][n-1-j] = m[j][n-1-i];
            m[j][n-1-i] = a;
        }
    }
}

template <int n> void dump(int m[n][n])
{
    cout << "M=\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) cout << '\t' << m[i][j];
        cout << '\n';
    }
}

int main()
{
    int m1[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    dump(m1);
    for (int i = 0; i < 4; ++i) { rotate(m1); dump(m1); }

    int m2[][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };
    dump(m2);
    for (int i = 0; i < 4; ++i) { rotate(m2); dump(m2); }

    return 0;
}
