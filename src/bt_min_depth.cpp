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

int get_min_depth(const node<int>* root)
{
    if (!root) return 0;
    if (!root->left) return get_min_depth(root->right) + 1;
    if (!root->right) return get_min_depth(root->left) + 1;
    return min(get_min_depth(root->left), get_min_depth(root->right)) + 1;
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
    int min_depth = get_min_depth(root);
    cout << "min depth: " << min_depth << '\n';
    delete root;
}

int main()
{
    solve("4(3(21)5(67))");
    solve("1(2(3(4(36)5)4)2(3(12)4(5(6(7(98)8)7)5)))");
    return 0;
}