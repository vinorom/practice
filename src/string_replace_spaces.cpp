#include <bits/stdc++.h>

using namespace std;

void replace_spaces(char* str)
{
    if (!str) return;

    int len = 0;
    int scount = 0;
    for (char* s = str; *s; s++)
    {
        ++len;
        if (*s == ' ') ++scount;
    }

    int new_len = len + 2 * scount;
    str[new_len] = 0;

    for (auto ns = str + new_len - 1, s = str + len - 1; s >= str; --s)
    {
        if (*s == ' ') *ns-- = '0', *ns-- = '2', *ns-- = '%';
        else *ns-- = *s;
    }
}

int main()
{
    char s[100] = "Mr John Smith";
    cout << '\'' << s << '\'' << '\n';
    replace_spaces(s);
    cout << '\'' << s << '\'' << '\n';

    return 0;
}
