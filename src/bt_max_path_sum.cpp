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

int get_max_path_sum(const node<int>* root, int& total_max_sum)
{
    if (!root) return 0;
    int max_left = get_max_path_sum(root->left, total_max_sum);
    int max_right = get_max_path_sum(root->right, total_max_sum);
    int res = max(root->key, max(max_left, max_right) + root->key);
    total_max_sum = max(total_max_sum, max(res, max_left + max_right + root->key));
    return res;
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
    int total_max_sum = numeric_limits<int>::min();
    int max_sum = get_max_path_sum(root, total_max_sum);
    cout << "max path sum: " << total_max_sum << '\n';
    delete root;
}

int main()
{
    solve("4(3(21)5(67))");
    solve("1(2(3(4(36)5)4)2(3(12)4(5(6(7(98)8)7)5)))");
    return 0;
}