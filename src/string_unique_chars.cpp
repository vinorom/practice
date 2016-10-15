#include <bits/stdc++.h>

using namespace std;

bool has_all_unique_chars(const char* str)
{
    if (!str) return true;

    bitset<256> char_exists;
    for (const char* s = str; *s; ++s)
    {
        assert(*s >= 0 && *s < 256);
        if (char_exists.test(*s)) return false;
        char_exists.set(*s, true);
    }

    return true;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        cout << (has_all_unique_chars(s.c_str()) ? "YES" : "NO") << '\n';
    }

    return 0;
}
