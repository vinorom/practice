#include <bits/stdc++.h>

using namespace std;

struct Dictionary
{
    bool resolve(const std::string& word) const
    {
        static const unordered_set<string> WORDS = { "and", "or", "far", "andromeda", "one", "11" };
        return WORDS.find(word) != WORDS.end();
    }
};

string split_words(const string& str, const Dictionary& dic)
{
    stack<size_t> pos;
    pos.push(0);
    auto i = pos.top();

    while (i < str.length())
    {
        bool found = false;
        for (++i; i <= str.length(); ++i)
        {
            size_t start_pos = pos.empty() ? 0 : pos.top();
            if (i - start_pos > 20) break;
            if (dic.resolve(str.substr(start_pos, i - start_pos)))
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (pos.empty()) break;
            i = pos.top();
            pos.pop();
        }
        else
        {
            pos.push(i);
        }
    }

    stack<size_t> rev_pos;
    while (!pos.empty())
    {
        rev_pos.push(pos.top());
        pos.pop();
    }

    stringstream ss;
    while (rev_pos.size() > 1)
    {
        auto p = rev_pos.top();
        rev_pos.pop();
        ss << str.substr(p, rev_pos.top() - p) << ' ';
    }
    auto start_pos = rev_pos.empty() ? 0 : rev_pos.top();
    ss << str.substr(start_pos);

    return ss.str();
}

string solve(const string& str)
{
    static Dictionary dic;

    cout << "str: \"" << str << "\"\n";
    auto new_str = split_words(str, dic);
    cout << "new str: \"" << new_str << "\"\n";
    return new_str;
}

int main()
{
    solve("onefarandromeda11");
    solve("oneandromeda");
    solve("onesandromeda");
    solve("farone11andromeda");
    solve("");

    return 0;
}
