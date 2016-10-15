#include <bits/stdc++.h>

using namespace std;

bool is_substr(const string& s, const string& substr)
{
    return s.find(substr) != string::npos;
}

bool is_rotation(const string& s1, const string& s2)
{
    if (s1.length() != s2.length()) return false;
    for (size_t i = 0; i < s1.length(); ++i)
    {
        if (is_substr(s2, s1.substr(0, i)) && is_substr(s2, s1.substr(i))) return true;
    }
    return false;
}

int main()
{
    cout << (is_rotation("waterbottle", "erbottlewat") ? "YES" : "NO") << '\n';
    cout << (is_rotation("qwerty", "qwerty") ? "YES" : "NO") << '\n';
    cout << (is_rotation("aaaabbaaa", "aabbaaaaa") ? "YES" : "NO") << '\n';
    cout << (is_rotation("abbaabba", "aabbaabb") ? "YES" : "NO") << '\n';
    cout << (is_rotation("q", "q") ? "YES" : "NO") << '\n';
    cout << (is_rotation("123", "321") ? "YES" : "NO") << '\n';
    return 0;
}
