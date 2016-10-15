#include <bits/stdc++.h>

using namespace std;

void reverse(char* s)
{
    if (!s) return;

    auto l = strlen(s);
    for (auto sl = s, sr = (s + l) - 1; sl < sr; ++sl, --sr) swap(*sl, *sr);
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        char s[1000];
        cin.getline(s, 1000);
        reverse(s);
        cout << s << '\n';
    }

    return 0;
}
