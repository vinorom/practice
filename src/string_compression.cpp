#include <bits/stdc++.h>

using namespace std;

int get_num_digits(int n)
{
    int count = 0;
    while (n) ++count, n /= 10;
    return count;
}

string compress(const string& s)
{
    if (s.empty()) return s;

    vector<pair<char, int>> letters{{s[0], 1}};
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] != letters.back().first)
        {
            letters.push_back({s[i], 1});
        }
        else
        {
            letters.back().second++;
        }
    }

    int compressed_len = 0;
    for (auto l: letters) compressed_len += 1 + get_num_digits(l.second);

    if (compressed_len >= s.length()) return s;

    stringstream ss;
    for (auto l: letters) ss << l.first << l.second;

    return ss.str();
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        cout << compress(s) << '\n';
    }
    return 0;
}
