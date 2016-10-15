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

bool is_bt_full(const node<int>* root)
{
    if (!root) return true;
    if ((root->left == nullptr) == (root->right == nullptr)) return is_bt_full(root->left) && is_bt_full(root->right);
    return false;
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
        if (*str != ')') root->right = read_tree(str);
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
    auto is_full = is_bt_full(root);
    cout << "is full: " << (is_full ? "YES" : "NO") << '\n';
    delete root;
}

int main()
{
    solve("4(3(21)5(67))");
    solve("1(2(3(4(3)5)4)2(3(12)4(5(6(7(98)8)7)5)))");
    return 0;
}