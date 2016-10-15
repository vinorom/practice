#include <bits/stdc++.h>

using namespace std;

template <int M> void set0(int m[][M], int N)
{
    vector<int> rows, cols;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (m[i][j] == 0) rows.push_back(i), cols.push_back(j);
        }
    }
    for (size_t i = 0; i < rows.size(); ++i)
    {
        for (int j = 0; j < M; ++j) m[rows[i]][j] = 0;
    }
    for (size_t j = 0; j < cols.size(); ++j)
    {
        for (int i = 0; i < N; ++i) m[i][cols[j]] = 0;
    }
}

template <int M> void dump(int m[][M], int N)
{
    cout << "M=\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j) cout << '\t' << m[i][j];
        cout << '\n';
    }
}

int main()
{
    int m[3][5] = {
        {1, 0, 3, 4, 5},
        {6, 7, 8, 0, 10},
        {11, 12, 13, 14, 15}
    };
    dump(m, 3);
    set0(m, 3);
    dump(m, 3);

    return 0;
}
