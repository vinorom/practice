#include <bits/stdc++.h>

using namespace std;

bool is_permutation(const string& s1, const string& s2)
{
    if (s1.length() != s2.length()) return false;

    int sc[256];
    fill(sc, sc + 256, 0);

    for (auto c: s1) sc[c]++;
    for (auto c: s2)
    {
        if (--sc[c] < 0) return false;
    }

    return true;
}

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (is_permutation(s1, s2) ? "YES" : "NO") << '\n';

    }
    return 0;
}
