#include <bits/stdc++.h>

using namespace std;

template <typename T> struct node
{
    node* left = nullptr;
    node* right = nullptr;
    T key;

    ~node()
    {
        delete left;
        delete right;
    }
};

int get_longest_inc_chain(const node<int>* root, int len, int value)
{
    if (!root) return len;

    int l = len;
    if (root->key != value + 1) l = 0;

    int left_len = get_longest_inc_chain(root->left, l + 1, root->key);
    int right_len = get_longest_inc_chain(root->right, l + 1, root->key);

    return max(max(left_len, right_len), len);
}

node<int>* read_tree(const char*& str)
{
    if (*str == 0) return nullptr;

    assert(isdigit(*str));
    node<int>* root = new node<int>;
    root->key = *str++ - '0';
    if (*str != 0 && *str == '(')
    {
        root->left = read_tree(++str);
        root->right = read_tree(str);
        ++str; // )
    }
    return root;
}

string dump_tree(const node<int>* root)
{
    if (!root) return "";
    stringstream ss;
    ss << root->key;
    if (root->left || root->right) ss << '(' << dump_tree(root->left) << dump_tree(root->right) << ')';
    return ss.str();
}

void solve(const char* tree)
{
    auto root = read_tree(tree);
    cout << "tree: " << dump_tree(root) << '\n';
    int len = get_longest_inc_chain(root, 0, -100);
    cout << "max len: " << len << '\n';
    delete root;
}

int main()
{
    solve("4(3(21)5(67))");
    solve("1(2(3(4(36)5)4)2(3(12)4(5(6(7(98)8)7)5)))");

    return 0;
}
